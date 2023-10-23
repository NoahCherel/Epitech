/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** IDirectoryLister
*/

#include "IDirectoryLister.hpp"
#include <cstring>

IDirectoryLister::OpenFailureException::OpenFailureException(const std::string &err) : err(err) {}

const char *IDirectoryLister::OpenFailureException::what() const noexcept {
    return strerror(errno);
}

const char *IDirectoryLister::NoMoreFileException::what() const noexcept {
    return "End of stream";
}
