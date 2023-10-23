/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Output
*/

#include "../Include/Output.hpp"

Output::Output(const std::string& name) : m_name(name), m_value(false) {}

const std::string& Output::getName() {
    return m_name;
}

bool Output::getValue() {
    return m_value;
}

void Output::setValue(bool value) {
    m_value = value;
}
