/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** TextClass
*/

#ifndef TEXTCLASS_HPP_
    #define TEXTCLASS_HPP_
    #include "../Corefiles/Core.hpp"
    #include "../IMonitorDisplay.hpp"
    #include <ncurses.h>
    #include <iostream>
    #include <string>
    #include <cstring>
    #include <thread>
    #include <chrono>
    #include <cmath>
    #include <fstream>
    #include <sstream>
    #include <vector>
    #include <unistd.h>
    #include <ifaddrs.h>
    #include <sys/utsname.h>
    #include <sys/sysinfo.h>
    #include <sys/statvfs.h>

    class TextClass : public IMonitorDisplay {
        public:
            TextClass();
            ~TextClass();
            void dispText(WINDOW *win);
            void initNCurses();
        protected:
        private:
    };

#endif /* !TEXTCLASS_HPP_ */
