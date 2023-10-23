/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** XOR
*/

#ifndef XOR_HPP_
#define XOR_HPP_

#include <vector>
#include <string>
#include "IComponent.hpp"

namespace nts {
    class XOR : public IComponent {
        public:
            XOR();
            explicit XOR(const std::string &value);
            virtual ~XOR() = default;

            nts::Tristate compute(std::size_t pin = 1) override;
            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
            void dump() const override;

        private:
            std::vector<nts::IComponent *> _pins;
            std::vector<std::size_t> _otherPins;
    };
}

#endif /* !XOR_HPP_ */
