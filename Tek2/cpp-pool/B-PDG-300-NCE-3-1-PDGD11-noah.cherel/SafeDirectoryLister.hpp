/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** SafeDirectoryLister
*/

#ifndef SAFEDIRECTORYLISTER_HPP_
#define SAFEDIRECTORYLISTER_HPP_

#include <dirent.h>
#include <iostream>
#include <string>
#include <exception>
#include <cstring>
#include "IDirectoryLister.hpp"

class SafeDirectoryLister : public IDirectoryLister {
public:
    SafeDirectoryLister(): dir(nullptr) {}
    SafeDirectoryLister(const std::string& path, bool hidden) : dir(nullptr) { open(path, hidden); }
    ~SafeDirectoryLister() { close(); }

    bool open(const std::string& path, bool hidden) {
        close();
        dir = opendir(path.c_str());
        if (!dir) {
            throw OpenFailureException(strerror(errno));
        }
        this->hidden = hidden;
        return true;
    }
    std::string get() {
    if (!dir) {
        throw NoMoreFileException();
    }
    struct dirent* ent;
    while ((ent = readdir(dir)) != nullptr) {
        if (!hidden && ent->d_name[0] == '.') {
            continue;
        }
        return ent->d_name;
    }
    throw NoMoreFileException();
    }

private:
    DIR* dir;
    bool hidden;
    void close() {
        if (dir) {
            closedir(dir);
            dir = nullptr;
        }
    }
};

#endif /* !SAFEDIRECTORYLISTER_HPP_ */
