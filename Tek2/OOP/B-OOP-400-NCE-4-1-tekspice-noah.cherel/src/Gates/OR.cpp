/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** OR
*/

#include "../../Include/OR.hpp"

namespace nts {
    OR::OR()
    {
        _pins.resize(3, nullptr);
        _otherPins.resize(3, 0);
    }

    nts::Tristate OR::compute(std::size_t pin)
    {
        if (pin == 3) {
            auto a = _pins[0]->compute(_otherPins[0]);
            auto b = _pins[1]->compute(_otherPins[1]);
            if (a == nts::Tristate::TRUE || b == nts::Tristate::TRUE)
                return nts::Tristate::TRUE;
            else if (a == nts::Tristate::FALSE && b == nts::Tristate::FALSE)
                return nts::Tristate::FALSE;
            else
                return nts::Tristate::UNDEFINED;
        }
        return _pins[pin - 1]->compute(_otherPins[pin - 1]);
    }

    void OR::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
    {
        if (pin <= 0 || pin > 3)
            throw std::out_of_range("OR pin out of range");
        _pins[pin - 1] = &other;
        _otherPins[pin - 1] = otherPin;
    }

    void OR::dump() const
    {
        std::cout << "OR gate" << std::endl;
    }

    OR::OR(const std::string &value)
    {
        _pins.resize(3, nullptr);
        _otherPins.resize(3, 0);
        (void)value;
    }

}
