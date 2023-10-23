/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Toy
*/

#ifndef TOY_HPP_
#define TOY_HPP_

#include "Picture.hpp"
#include <string>

class Toy {
    public:
        Toy();
        ~Toy();
        enum ToyType {
            BASIC_TOY,
            ALIEN,
            BUZZ,
            WOODY
        };
        ToyType getType() const;
        std::string getName() const;
        void setName(std::string name);
        bool setAscii(std::string file);
        std::string getAscii() const;
        Toy(ToyType type, std::string name, std::string file);
        Toy(Toy const &toy);
        Toy &operator=(Toy const &toy);
        Toy &operator<<(std::string const &str);

    protected:
        ToyType type;
        std::string name;
        Picture picture;
    private:
};

std::ostream &operator<<(std::ostream &os, Toy const &toy);


#endif /* !TOY_HPP_ */
