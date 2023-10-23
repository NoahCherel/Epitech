/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Command
*/

#include "Command.hpp"

void Command::registerCommand(const std::string &name, const std::function<void()> &function) {
    if (_commands.find(name) != _commands.end()) {
        throw Error("Already registered command");
    }
    _commands[name] = function;
}

void Command::executeCommand(const std::string &name) {
    auto it = _commands.find(name);
    if (it == _commands.end()) {
        throw Error("Unknow command");
    }
    it->second();
}
