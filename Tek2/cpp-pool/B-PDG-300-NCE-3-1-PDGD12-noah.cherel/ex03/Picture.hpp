/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Picture
*/

#ifndef PICTURE_HPP_
#define PICTURE_HPP_

#include <string>
#include <fstream>

class Picture {
    public:
        Picture();
        ~Picture();
        Picture(const Picture &picture);
        Picture &operator=(const Picture &picture);
        Picture(const std::string &file);
        bool getPictureFromFile(const std::string &file);
        std::string data;
    protected:
    private:
};


#endif /* !PICTURE_HPP_ */
