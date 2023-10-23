#!/usr/bin/env python3
##
# EPITECH PROJECT, 2023
# B-YEP-400-NCE-4-1-zappy-noah.cherel
# File description:
# main
##


import sys
import os
import math
import time
import random
import socket
import select
import errno
import re

from ai.Player import Player

LOG = 2 # 0: no log, 1: only action commands, 2: all commands

def help(args):
    """
    Display help information.

    This function displays the usage and description of the program's
    command line arguments.

    Args:
        args (list): The command line arguments.

    Returns:
        int: The exit code indicating the execution status.
    """
    print(f"USAGE: {args[0]} -p port -n name -h machine")
    print("\tport\tis the port number")
    print("\tname\tis the name of the team")
    print("\tmachine\tis the name of the machine; localhost by default")
    return 84


def parseArgs(args):
    """
    Parse command line arguments.

    This function parses the command line arguments and extracts the port
    number, team name, and machine name.

    Args:
        args (list): The command line arguments.

    Returns:
        tuple: A tuple containing the port number, team name, and machine name.
    """
    port = 0
    name = ""
    machine = "localhost"
    for i in range(1, len(args)):
        if (args[i] == "-p"):
            port = int(args[i + 1])
        if (args[i] == "-n"):
            name = args[i + 1]
        if (args[i] == "-h"):
            machine = args[i + 1]
    return port, name, machine


def getInventoryFromResponse(player, inventory):
    """
    Generate a dictionary from the inventory response.

    This function parses the inventory response received from the server and
    creates a dictionary representing the inventory.
    Example entry:
        [ food 84, linemate 2, deraumere 1, sibur 1, mendiane 0, phiras 1, thystame 0 ]
    Example output:
        { "food": 84, "linemate": 2, "deraumere": 1, "sibur": 1, "mendiane": 0, "phiras": 1, "thystame": 0 }

    Args:
        player (Player): The player object.
        inventory (str): The inventory response from the server.

    Returns:
        dict: The parsed inventory dictionary.
    """
    try:
        inventory = inventory.split(" ") # split on space
        inventory[-1] = inventory[-1][:-1] # remove \n
        inventory = inventory[1:-1] # remove first and last element
        inv = {}
        for i in range(0, len(inventory), 2):
            if ',' in inventory[i + 1]: # remove comma
                inventory[i + 1] = inventory[i + 1][:-1]
            inv[inventory[i]] = int(inventory[i + 1])
        return inv
    except:
        return "ko"


def getVisionFromResponse(player, vision):
    """
    Generate a list from the vision response.

    This function parses the vision response received from the server and
    creates a list representing the vision.
    Example entry:
        [ player phiras, food food deraumere mendiane, food food phiras, food food food ]
    Example output:
        [ [ "player", "phiras" ], [ "food", "food", "deraumere", "mendiane" ], [ "food", "food", "phiras" ], [ "food", "food", "food" ] ]

    Args:
        player (Player): The player object.
        vision (str): The vision response from the server.

    Returns:
        list: The parsed vision list.
    """
    try:
        vision = vision[2:-3]
        new_vision = re.split(r',\s*', vision)  # Split on ',' or ', '
        for i in range(len(new_vision)):
            new_vision[i] = new_vision[i].split(" ")
        return new_vision
    except:
        return "ko"


def sendCommand(sock, command, log_level):
    """
    Send a command to the server.

    This function sends a command to the server and logs it if the log level
    is set to 1 or higher.

    Args:
        sock (socket): The socket connected to the server.
        command (str): The command to send to the server.
        log_level (int): The log level.
    """
    sock.send((command + "\n").encode())
    if (LOG >= log_level): print(f'<--{command}')


def waitForResponse(sock):
    """
    Wait for a response from the server.

    This function waits for a response byte by byte from the server.

    Args:
        sock (socket): The socket connected to the server.
        log_level (int): The log level.

    Returns:
        str: The response from the server.
    """
    response = ""
    start_time = time.time()
    while True:
        try:
            data = sock.recv(1).decode()
            if data == '\n':
                break
            response += data
        except socket.error as e:
            print(e)
            sys.exit(1)
        elapsed_time = time.time() - start_time
        if elapsed_time > 5:
            print("\033[91mConnection timed out\033[0m")
            exit(0)
    response += '\n'
    return response

def waitForLookResponse(player, sock):
    response = ""
    while not response.startswith("[ player"):
        response = waitForResponse(sock)
        player.operateReceivedCommand(response)
        if (LOG >= 1):
            if ("ko" in response):
                print("\033[93m-->" + response + "\033[0m", end='')
            elif (response.startswith("[") or response.startswith("{")) and LOG >= 2:
                print("\033[92m-->" + response + "\033[0m", end='')
            elif ("ok" in response or response.startswith("Elevation underway") or response.startswith("Current level:")):
                print("\033[92m-->" + response + "\033[0m", end='')
            elif ("dead" in response):
                print("\033[91m-->" + response + "\033[0m", end='')
                exit(0)
            elif not (response.startswith("[") or response.startswith("{")):
                print(f'-->{response}', end='')
    return response

def waitForInventoryResponse(player, sock):
    response = ""
    while not response.startswith("[ food"):
        response = waitForResponse(sock)
        player.operateReceivedCommand(response)
        if (LOG >= 1):
            if ("ko" in response):
                print("\033[93m-->" + response + "\033[0m", end='')
            elif (response.startswith("[") or response.startswith("{")) and LOG >= 2:
                print("\033[92m-->" + response + "\033[0m", end='')
            elif ("ok" in response or response.startswith("Elevation underway") or response.startswith("Current level:")):
                print("\033[92m-->" + response + "\033[0m", end='')
            elif ("dead" in response):
                print("\033[91m-->" + response + "\033[0m", end='')
                exit(0)
            elif not (response.startswith("[") or response.startswith("{")):
                print(f'-->{response}', end='')
    return response

def main(args):
    """
    Main program logic.

    This function contains the main logic of the program.

    Args:
        args (list): The command line arguments.

    Returns:
        int: The exit code indicating the execution status.
    """
    player = Player(args[3])
    port, name, machine = parseArgs(args)
    try:
        sock = player.connectToServer(port, name, machine)
    except Exception as e:
        print(e)
        return 1
    while True:
        try:
            sendCommand(sock, "Look", 2)
            vision = waitForLookResponse(player, sock)
            sendCommand(sock, "Inventory", 2)
            inventory = waitForInventoryResponse(player, sock)
            vision = getVisionFromResponse(player, vision)
            inventory = getInventoryFromResponse(player, inventory)
            if (vision != "ko"):
                player.setVision(vision)
            if (inventory != "ko"):
                player.setInventory(inventory)
            command = player.getCommand()
            if (command == ""):
                continue
            sendCommand(sock, command, 1)
            waitForResponse(sock)
        except KeyboardInterrupt:
            sock.close()
            return 0
        except socket.error as e:
            print(e)
            sock.close()
            return 0


if __name__ == "__main__":
    if (len(sys.argv) < 5 or sys.argv[1] == "-help" or sys.argv[1] == "-h"):
        sys.exit(help(sys.argv))
    sys.exit(main(sys.argv))
