/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Component
*/

#ifndef COMPONENT_HPP_
#define COMPONENT_HPP_

#include <string>
#include <vector>
#include <memory>
#include "IComponent.hpp"

namespace nts {

    class Component : public IComponent {
    public:
        Component(const std::string &type);
        virtual ~Component() = default;

        virtual void simulate(std::size_t tick);
        virtual nts::Tristate compute(std::size_t pin);

        virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
        virtual std::vector<std::unique_ptr<nts::IComponent>> &getInnerComponents();
        virtual std::string getName();

    protected:
        std::string _name;
        std::vector<std::unique_ptr<nts::IComponent>> _innerComponents;
        std::vector<nts::Tristate> _pins;
        std::vector<std::pair<nts::IComponent*, size_t>> _links;
    };

}

#endif // COMPONENT_HPP_

