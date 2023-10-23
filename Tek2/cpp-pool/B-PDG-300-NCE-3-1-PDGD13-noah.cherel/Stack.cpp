/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Stack
*/

#include "Stack.hpp"

void Stack::push(double value)
{
    _stack.push(value);
}

double Stack::pop()
{
    if (_stack.empty())
        throw Error("Empty stack");
    double value = _stack.top();
    _stack.pop();
    return value;
}

double Stack::top() const
{
    if (_stack.empty())
        throw Error("Empty stack");
    return _stack.top();
}

void Stack::add()
{
    if (_stack.size() < 2)
        throw Error("Not enough operands");
    double a = _stack.top();
    _stack.pop();
    double b = _stack.top();
    _stack.pop();
    _stack.push(a + b);
}

void Stack::sub()
{
    if (_stack.size() < 2)
        throw Error("Not enough operands");
    double a = _stack.top();
    _stack.pop();
    double b = _stack.top();
    _stack.pop();
    _stack.push(a - b);
}

void Stack::mul()
{
    if (_stack.size() < 2)
        throw Error("Not enough operands");
    double a = _stack.top();
    _stack.pop();
    double b = _stack.top();
    _stack.pop();
    _stack.push(a * b);
}

void Stack::div()
{
    if (_stack.size() < 2)
        throw Error("Not enough operands");
    double a = _stack.top();
    _stack.pop();
    double b = _stack.top();
    _stack.pop();
    if (b == 0)
        throw Error("Division by zero");
    _stack.push(a / b);
}

std::ostream &operator<<(std::ostream &os, const Stack &stack)
{
    std::stack<double> tmp = stack._stack;
    while (!tmp.empty()) {
        os << tmp.top() << std::endl;
        tmp.pop();
    }
    return os;
}