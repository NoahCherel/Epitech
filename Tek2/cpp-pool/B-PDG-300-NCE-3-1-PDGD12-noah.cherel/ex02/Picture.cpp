/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Picture
*/

#include "Picture.hpp"

Picture::Picture() : data("")
{
}

Picture::~Picture()
{
}

Picture::Picture(const Picture &picture) : data(picture.data)
{
}

Picture &Picture::operator=(const Picture &picture)
{
    data = picture.data;
    return *this;
}

Picture::Picture(const std::string &file) : data("")
{
    getPictureFromFile(file);
}

bool Picture::getPictureFromFile(const std::string &file)
{
    std::ifstream fileStream(file);
    std::string line;
    std::string data;

    if (!fileStream.is_open()) {
        data = "ERROR";
        this->data = data;
        return false;
    }
    while (getline(fileStream, line))
        data += line + "\n";
    this->data = data;
    return true;
}