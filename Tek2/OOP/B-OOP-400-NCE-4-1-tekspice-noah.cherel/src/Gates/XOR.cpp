/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** XOR
*/

#include "../../Include/XOR.hpp"

namespace nts {
    XOR::XOR()
    {
        _pins.resize(3, nullptr);
        _otherPins.resize(3, 0);
    }

    XOR::XOR(const std::string &value)
    {
        _pins.resize(3, nullptr);
        _otherPins.resize(3, 0);
        (void)value;
    }

    nts::Tristate XOR::compute(std::size_t pin)
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

    void XOR::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
    {
        if (pin <= 0 || pin > 3)
            throw std::out_of_range("XOR pin out of range");
        _pins[pin - 1] = &other;
        _otherPins[pin - 1] = otherPin;
    }

    void XOR::dump() const
    {
        std::cout << "XOR gate" << std::endl;
    }
}
