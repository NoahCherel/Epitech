/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-raytracer-marc-olivier.koban
** File description:
** ILight
*/

#ifndef ILIGHT_HPP_
    #define ILIGHT_HPP_

    #include <iostream>
    #include <string>

    #include <libconfig.h++>
    using namespace libconfig;

    class ILight {
        public:
            ILight() = default;
            virtual ~ILight() = default;

        protected:
        private:
    };

#endif /* !ILIGHT_HPP_ */
