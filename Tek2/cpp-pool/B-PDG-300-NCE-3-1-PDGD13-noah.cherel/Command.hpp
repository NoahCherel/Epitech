/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Command
*/

#ifndef COMMAND_HPP_
#define COMMAND_HPP_

#include <iostream>
#include <string>
#include <map>
#include <functional>

class Command {
    public:
        class Error : public std::exception {
            public:
                Error(std::string const &message) : _message(message) {}
                const char *what() const noexcept override { return _message.c_str(); }
            private:
                std::string _message;
        };
        void registerCommand(const std::string &name, const std::function<void()> &function);
        void executeCommand(const std::string &name);
    private:
        std::map<std::string, std::function<void()>> _commands;
};

#endif /* !COMMAND_HPP_ */
