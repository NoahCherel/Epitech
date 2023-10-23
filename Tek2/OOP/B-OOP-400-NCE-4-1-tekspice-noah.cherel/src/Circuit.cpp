/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Circuit
*/

#include "../Include/Circuit.hpp"

void Circuit::addInput(const std::string &name) {
    _inputs.push_back(name);
}

void Circuit::addOutput(const std::string &name) {
    _outputs.push_back(name);
}

void Circuit::addGate(const std::string &type, const std::vector<std::string> &inputs, const std::string &output) {
    Gate gate;
    gate.name = type;
    for (auto &input : inputs) {
        gate.inputs.push_back(std::stoi(input));
    }
    gate.output = std::stoi(output);
    _gates.push_back(gate);
}

void Circuit::simulate() {}


void Circuit::dump() const {
    for (auto &gate : _gates) {
        std::cout << gate.name << " ";
        for (auto &input : gate.inputs) {
            std::cout << input << " ";
        }
        std::cout << gate.output << std::endl;
    }
}