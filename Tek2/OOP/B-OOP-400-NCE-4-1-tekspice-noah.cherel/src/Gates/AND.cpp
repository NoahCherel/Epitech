/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** AND
*/

#include "../../Include/AND.hpp"

namespace nts {
    AND::AND()
    {
        _pins.resize(3, nullptr);
        _otherPins.resize(3, 0);
    }

    AND::AND(const std::string &value)
    {
        _pins.resize(3, nullptr);
        _otherPins.resize(3, 0);
        (void)value;
    }

    nts::Tristate AND::compute(std::size_t pin)
    {
        if (pin == 3) {
            auto a = _pins[0]->compute(_otherPins[0]);
            auto b = _pins[1]->compute(_otherPins[1]);
            if (a == nts::Tristate::TRUE && b == nts::Tristate::TRUE)
                return nts::Tristate::TRUE;
            else if (a == nts::Tristate::FALSE || b == nts::Tristate::FALSE)
                return nts::Tristate::FALSE;
            else
                return nts::Tristate::UNDEFINED;
        }
        return _pins[pin - 1]->compute(_otherPins[pin - 1]);
    }

    void AND::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
    {
        if (pin <= 0 || pin > 3)
            throw std::out_of_range("AND pin out of range");
        _pins[pin - 1] = &other;
        _otherPins[pin - 1] = otherPin;
    }

    void AND::dump() const
    {
        std::cout << "AND gate" << std::endl;
    }
}
