/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Circuit
*/

#ifndef CIRCUIT_HPP_
#define CIRCUIT_HPP_

#include "IComponent.hpp"
#include "Input.hpp"
#include "Output.hpp"
#include "Parser.hpp"

#include <memory>
#include <string>
#include <utility>
#include <vector>
#include <unordered_map>

#include <vector>
#include <string>

struct Gate {
    std::string name;
    std::vector<int> inputs;
    int output;
};

class Circuit {
public:
    Circuit() = default;
    ~Circuit() = default;

    void addInput(const std::string& name);
    void addOutput(const std::string& name);
    void addGate(const std::string& type, const std::vector<std::string>& inputs, const std::string& output);

    std::vector<std::string> getInputs() const;
    std::vector<std::string> getOutputs() const;
    std::vector<Gate> getGates() const;

    void simulate();

    void dump() const;

private:
    std::vector<Gate> _gates;
    std::vector<std::string> _inputs;
    std::vector<std::string> _outputs;
};

#endif /* !CIRCUIT_HPP_ */
