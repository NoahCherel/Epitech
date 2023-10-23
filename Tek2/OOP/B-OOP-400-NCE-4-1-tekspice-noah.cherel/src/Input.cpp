/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Input
*/

#include "../Include/Input.hpp"

Input::Input(const std::string& name) : name_(name), value_(nts::UNDEFINED) {}

void Input::setValue(nts::Tristate value) {
    value_ = value;
}

nts::Tristate Input::getValue() {
    return value_;
}

std::string Input::getName() {
    return name_;
}