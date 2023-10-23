/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Input
*/

#ifndef INPUT_HPP_
#define INPUT_HPP_

#include "IComponent.hpp"

class Input {

public:
    Input(const std::string& name);

    void setValue(nts::Tristate value);
    nts::Tristate getValue();
    std::string getName();

private:
    std::string name_;
    nts::Tristate value_;
};

#endif /* !INPUT_HPP_ */