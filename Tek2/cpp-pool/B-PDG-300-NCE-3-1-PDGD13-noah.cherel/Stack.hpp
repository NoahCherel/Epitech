/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Stack
*/

#ifndef STACK_HPP_
#define STACK_HPP_

#include <stack>
#include <iostream>
#include <string>

class Stack {
    public:
        std::stack<double> _stack;
        void push(double value);
        double pop();
        double top() const;
        void add();
        void sub();
        void mul();
        void div();
        class Error : public std::exception {
            public:
                Error(std::string const &message) : _message(message) {}
                const char *what() const noexcept override { return _message.c_str(); }
            private:
                std::string _message;
        };
};

std::ostream &operator<<(std::ostream &os, const Stack &stack);


#endif /* !STACK_HPP_ */
