/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** IMonitorModule
*/

#ifndef IMONITORMODULE_HPP_
#define IMONITORMODULE_HPP_

#include <string>
#include <iostream>

class IMonitorModule {
    public:
        virtual ~IMonitorModule() = default;
        virtual std::string getData() = 0;
        int level;
    protected:
    private:
};

#endif /* !IMONITORMODULE_HPP_ */
