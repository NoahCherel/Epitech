/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** DirectoryLister
*/

#ifndef DIRECTORYLISTER_HPP_
#define DIRECTORYLISTER_HPP_

#include "IDirectoryLister.hpp"
#include <dirent.h>
#include <iostream>
#include <string>

class DirectoryLister : public IDirectoryLister {
public:
    DirectoryLister() : dir(nullptr) {}
    DirectoryLister(const std::string &path, bool hidden) : dir(nullptr) { open(path, hidden); }
    ~DirectoryLister() { close(); }

    bool open(const std::string& path, bool hidden) {
        close();
        dir = opendir(path.c_str());
        if (!dir) {
            perror(path.c_str());
            return false;
        }
        this->hidden = hidden;
        return true;
    }

    std::string get() {
        if (!dir) {
            return "";
        }
        struct dirent* ent;
        while ((ent = readdir(dir)) != nullptr) {
            if (!hidden && ent->d_name[0] == '.') {
                continue;
            }
            return ent->d_name;
        }
        return "";
    }
    void close() {
        if (dir) {
            closedir(dir);
            dir = nullptr;
        }
    }

private:
    DIR* dir;
    bool hidden;
};

#endif /* !DIRECTORYLISTER_HPP_ */
