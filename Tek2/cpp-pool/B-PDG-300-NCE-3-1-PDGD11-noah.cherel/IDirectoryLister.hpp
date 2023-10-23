/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** IDirectoryLister
*/

#ifndef IDIRECTORYLISTER_HPP_
#define IDIRECTORYLISTER_HPP_


#include <iostream>
#include <string>
#include <dirent.h>
#include <exception>

class IDirectoryLister {
public:
    virtual bool open(const std::string& path, bool hidden) = 0;
    virtual std::string get() = 0;

        class  OpenFailureException : public std::exception {
            public:
                OpenFailureException(const std::string &err);
                const char *what() const noexcept;
            private:
                std::string err;
        };


        class  NoMoreFileException : public std::exception {
            public:
                const char *what() const noexcept;
        };
    private:
        DIR* dir = NULL;
        bool hidden;
};

#endif /* !IDIRECTORYLISTER_HPP_ */