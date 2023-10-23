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

    if (!fileStream.is_open()) {
        data = "ERROR";
        return false;
    }
    while (getline(fileStream, line))
        data += line + "\n";
    fileStream.close();
    return true;
}