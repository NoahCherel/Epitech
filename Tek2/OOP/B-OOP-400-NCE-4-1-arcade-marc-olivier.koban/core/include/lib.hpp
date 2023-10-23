/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** lib
*/

#ifndef LIB_HPP_
#define LIB_HPP_

#include <iostream>
#include <dlfcn.h>
#include <string>

class Lib {
public:
    void* lib;
    void loadLib(std::string path) {
        lib = dlopen(path.c_str(), RTLD_LAZY);
    }
    void closeLib() {
        if (lib) {
            dlclose(lib);
            lib = NULL;
        }
    }
    ~Lib() {
        closeLib();
    }
};

#endif /* !LIB_HPP_ */
