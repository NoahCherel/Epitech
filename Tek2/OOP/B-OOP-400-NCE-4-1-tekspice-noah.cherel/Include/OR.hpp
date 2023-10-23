/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** OR
*/

#ifndef OR_HPP_
#define OR_HPP_

#include <vector>
#include <string>
#include "IComponent.hpp"

namespace nts {
    class OR : public IComponent {
        public:
            OR();
            explicit OR(const std::string &value);
            virtual ~OR() = default;

            nts::Tristate compute(std::size_t pin = 1) override;
            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
            void dump() const override;

        private:
            std::vector<nts::IComponent *> _pins;
            std::vector<std::size_t> _otherPins;
    };
}

#endif /* !OR_HPP_ */
