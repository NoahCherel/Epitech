/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-arcade-marc-olivier.koban
** File description:
** ILibrary
*/

#ifndef ILIBRARY_HPP_
    #define ILIBRARY_HPP_

    #include <iostream>
    #include <string>
    #include <string.h>
    #include <errno.h>
    #include <memory>
    #include <vector>

    #define HEIGHT 10
    #define WIDTH 30
    class ILibrary {
        public:
            ILibrary() = default;
            virtual ~ILibrary() = default;
            virtual std::string getName() = 0;
            virtual void init() = 0;
            virtual void stop() = 0;
            virtual void clear() = 0;
            virtual void display(std::vector<std::string> map) = 0;
            virtual std::string getEvent() = 0;

        protected:
        private:
    };

#endif /* !ILIBRARY_HPP_ */
