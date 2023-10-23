/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** AFruit
*/

#ifndef AFRUIT_HPP_
#define AFRUIT_HPP_

#include "IFruit.hpp"

class AFruit : public IFruit {
    public:
        unsigned int getVitamins() const override;
        std::string getName() const override = 0;
        bool isPeeled() const override;
        void peel() override;
    protected:
        int _vitamins;
        bool _peeled;
};

#endif /* !AFRUIT_HPP_ */
