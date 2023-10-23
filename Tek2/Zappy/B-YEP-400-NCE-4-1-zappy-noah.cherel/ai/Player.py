##
## EPITECH PROJECT, 2023
## B-YEP-400-NCE-4-1-zappy-noah.cherel
## File description:
## Player
##


import socket
import random
import time

from ai.Elevation import Elevation

LOG = 2 # 0: no log, 1: only action commands, 2: all commands

class Player:
    def __init__(self, name):
        """Initialize a Player object.

        Args:
            name (str): The name of the team the player is in.
        """
        self.team = name
        self.level = 1
        self.inventory = {
            "food": 10,
            "linemate": 0,
            "deraumere": 0,
            "sibur": 0,
            "mendiane": 0,
            "phiras": 0,
            "thystame": 0
        }
        self.world_size = [0, 0]
        self.vision = []
        self.time_since_last_fork = 0
        self.number_of_rotations = 0
        self.last_broadcast_received = {
            "direction": "",
            "text": ""
        }

    def getTeam(self):
        """Get the name of the player's team.

        Returns:
            str: The name of the player's team.
        """
        return self.team

    def getLevel(self):
        """Get the level of the player.

        Returns:
            int: The level of the player.
        """
        return self.level

    def getInventory(self):
        """Get the inventory of the player.

        Returns:
            dict: The inventory of the player.
        """
        return self.inventory

    def getWorldSize(self):
        """Get the size of the world.

        Returns:
            list: The size of the world [width, height].
        """
        return self.world_size

    def getVision(self):
        """Get the vision of the player.

        Returns:
            list: The vision of the player.
        """
        return self.vision

    def getLastBroadcastReceived(self):
        """Get the last received broadcast message.

        Returns:
            str: The last received broadcast message.
        """
        return self.last_broadcast_received

    def setLevel(self, level):
        """Set the level of the player.

        Args:
            level (int): The level to set.
        """
        self.level = level

    def setInventory(self, inventory):
        """Set the inventory of the player.

        Args:
            inventory (dict): The inventory to set.
        """
        self.inventory = inventory

    def setWorldSize(self, world_size):
        """Set the size of the world.

        Args:
            world_size (list): The size of the world [width, height].
        """
        self.world_size = world_size

    def setVision(self, vision):
        """Set the vision of the player.

        Args:
            vision (list): The vision to set.
        """
        self.vision = vision

    def setLastBroadcastReceived(self, direction, text):
        """Set the last received broadcast message.

        Args:
            direction (str): The direction the broadcast is coming from.
            text (str): The text of the broadcast.
        """
        self.last_broadcast_received = {"direction": direction, "text": text}

    def connectToServer(self, port, name, machine):
        """Connect to the game server.

        Args:
            port (int): The port number.
            name (str): The name of the team.
            machine (str): The name of the machine.

        Returns:
            socket.socket: The socket object representing the connection.
        Raises:
            Exception: If failed to connect to the server.
        """
        sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        sock.setblocking(True)  # Set socket to blocking mode
        try:
            sock.connect((machine, port))
        except socket.error as e:
            raise Exception("Failed to connect to server: {}".format(e))
        # Get WELCOME message
        data = sock.recv(1024)
        if (LOG >= 1):
            if ("ko" in data.decode()):
                print("\033[93m-->" + data.decode() + "\033[0m", end='')
            elif ("ok" in data.decode() or data.decode().startswith("[") or data.decode().startswith("{")):
                print("\033[92m-->" + data.decode() + "\033[0m", end='')
            elif ("dead" in data.decode()):
                print("\033[91m-->" + data.decode() + "\033[0m", end='')
            else:
                print(f'-->{data.decode()}', end='')
        if (data.decode() == "ko"):
            raise Exception("Failed to connect to given team")
        sock.send((name + "\n").encode())
        if (LOG >= 1): print(f'<--{name}')
        # Client number and map size
        time.sleep(0.1)
        data = sock.recv(1024)
        if (LOG >= 1):
            if ("ko" in data.decode()):
                print("\033[93m-->" + data.decode() + "\033[0m", end='')
            elif ("ok" in data.decode() or data.decode().startswith("[") or data.decode().startswith("{")):
                print("\033[92m-->" + data.decode() + "\033[0m", end='')
            elif ("dead" in data.decode()):
                print("\033[91m-->" + data.decode() + "\033[0m", end='')
            else:
                print(f'-->{data.decode()}', end='')
        size = data.decode().split("\n")[1] # [0] is CLIENT-NUM (unused)
        size = size.split(" ")
        if (len(size) != 2 or not size[0].isdigit() or not size[1].isdigit()):
            raise Exception("Invalid server map size")
        self.setWorldSize([int(size[0]), int(size[1])])
        return sock

    def getCommand(self):
        """Get the command to be sent to the server.

        Returns:
            str: The command to be sent.
        """
        # if a broadcast was received, use it
        if (self.getLastBroadcastReceived()["text"] == str(self.getLevel()) and self.inventory["food"] > 15):
            if (self.getLastBroadcastReceived()["direction"] in "218"):
                self.setLastBroadcastReceived("", "")
                print("Broadcast received, going forward")
                return "Forward"
            elif (self.getLastBroadcastReceived()["direction"] in "34"):
                self.setLastBroadcastReceived("", "")
                print("Broadcast received, going left")
                return "Left"
            elif (self.getLastBroadcastReceived()["direction"] in "765"):
                self.setLastBroadcastReceived("", "")
                print("Broadcast received, going right")
                return "Right"
            self.setLastBroadcastReceived("", "")
        if (self.getLevel() < 8 and self.inventory["food"] > 5):
            # if player can elevate, elevate
            elevation_status = Elevation().check_elevation(self)
            self.time_since_last_fork += 1
            if elevation_status == "1":
                return "Incantation"
            elif elevation_status != "0": # or drop/take nessessary items
                if random.randint(0, 1) == 0 or self.inventory["food"] < 10:
                    return ""
                else:
                    return f'{elevation_status}'
        if (self.time_since_last_fork > 42 and self.inventory["food"] > 10):
            self.time_since_last_fork = 0
            return "Fork"
        # if something on the tile, take it
        for i in range(1, len(self.getVision()[0])):
            if (self.getVision()[0][i] in self.inventory):
                if (self.getVision()[0][i] == "food" and self.inventory["food"] < 50):
                    return "Take " + self.getVision()[0][i]
                elif (self.inventory[self.getVision()[0][i]] < 20):
                    return "Take " + self.getVision()[0][i]
        forward_indexes = [2]
        if (len(self.getVision()) > 4): forward_indexes.append(6)
        if (len(self.getVision()) > 9): forward_indexes.append(12)
        for i in forward_indexes: # if something in front, move forward
            if (len(self.getVision()[i]) > 0 and self.getVision()[i][0] in self.inventory):
                self.number_of_rotations = 0
                return "Forward"
        if (self.number_of_rotations > 3): # if rotated 4 times, move forward
            self.number_of_rotations = 0
            return "Forward"
        # if nothing in vision, rotate randomly
        rdm = random.randint(0, 1)
        self.number_of_rotations += 1
        return "Right" if rdm == 0 else "Left"

    def operateReceivedCommand(self, data):
        """
        Operate a received command.

        This method processes a received command and performs the necessary
        operations based on the command type.

        Args:
            data (str): The received command data.
        """
        data = data[:-1]
        if ("message" in data):
            if data.split(" ")[2] == str(self.getLevel()):
                self.setLastBroadcastReceived(data.split(" ")[1][0], data.split(" ")[2])
            return True
        elif ("Current level") in data:
            self.setLevel(self.getLevel() + 1)
        elif ("eject" in data):
            # do something on eject ?
            return True
        elif ("dead" in data):
            exit(0)
        return False
