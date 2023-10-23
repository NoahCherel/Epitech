/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** AND
*/

#ifndef AND_HPP_
#define AND_HPP_

#include <vector>
#include <string>
#include "IComponent.hpp"

namespace nts {
    class AND : public IComponent {
        public:
            AND();
            explicit AND(const std::string &value);
            virtual ~AND() = default;

            nts::Tristate compute(std::size_t pin = 1) override;
            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
            void dump() const override;

        private:
            std::vector<nts::IComponent *> _pins;
            std::vector<std::size_t> _otherPins;
    };
}

#endif /* !AND_HPP_ */
