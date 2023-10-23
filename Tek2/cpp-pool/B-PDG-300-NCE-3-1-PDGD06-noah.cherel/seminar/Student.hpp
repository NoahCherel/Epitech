/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Student
*/

#ifndef STUDENT_HPP_
#define STUDENT_HPP_

#include <iostream>
#include <string>
#include <algorithm>

class Student {
    public:
        Student(std::string name) : name_(name), energy_(100) {
            std::cout << "Student " << name_
            << ": I'm ready to learn C++." << std::endl;
        }
        ~Student() {
            std::cout << "Student " << name_ <<
            ": Wow, much learning today, very smart, such C++." << std::endl;
        }
        bool learn(std::string text) {
            if (energy_ < 42) {
                std::string::size_type pos = 0;
                while ((pos = text.find("C++", pos)) != std::string::npos) {
                    text.replace(pos, 3, "shit");
                    pos += 3;
                }
                std::cout << "Student " << name_ << ": " << text << std::endl;
                return false;
            }
            energy_ = energy_ - 42;
            std::cout << "Student " << name_ << ": " << text << std::endl;
            return true;
        }
        void drink(std::string drink) {
            int energy_boost = 0;
            if (drink == "Red Bull") {
                energy_boost = 32;
                std::cout << "Student " << name_
                <<": Red Bull gives you wings!" << std::endl;
            } else if (drink == "Monster") {
                energy_boost = 64;
                std::cout << "Student " << name_
                << ": Unleash The Beast!" << std::endl;
            } else {
                energy_boost = 1;
                std::cout << "Student " << name_
                << ": ah, yes... enslaved moisture." << std::endl;
            }
            energy_ = energy_ + energy_boost;
            if (energy_ > 100) energy_ = 100;
        }
        std::string getName() {
            return name_;
        }
    private:
        std::string name_;
        int energy_;
};

#endif /* !STUDENT_HPP_ */
