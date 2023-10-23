/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Dean
*/

#ifndef DEAN_HPP_
#define DEAN_HPP_

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "Student.hpp"
#include "Assistant.hpp"

class Dean {
public:
    Dean(std::string name) : name_(name) {
        std::cout << "Dean " << name_ << ": I'm Dean " << name_ << "! How do you do, fellow kids?" << std::endl;
        working_ = false;
    }
    ~Dean() {
        std::cout << "Dean " << name_ << ": Time to go home." << std::endl;
    }
    void teachStudent(Student* student, std::string lesson) {
        if (!student->learn(lesson)) {
            std::cout << "Dean " << name_ << ": All work and no play makes " << student->getName() << " a dull student." << std::endl;
            std::string drinks[] = {"Cristaline", "Monster", "Evian", "Red Bull", "Sierra Springs"};
            std::string drink = drinks[std::rand() % 5];
            std::ofstream file(student->getName() + ".drink");
            file << drink;
            file.close();
        }
    }
    void timeCheck() {
        if (working_) {
            std::cout << "Dean " << name_ << ": Don't forget to close the windows when you leave." << std::endl;
            working_ = false;
        } else {
            std::cout << "Dean " << name_ << ": Where is everyone?" << std::endl;
            working_ = true;
        }
    }
private:
    std::string name_;
    bool working_;
};


#endif /* !DEAN_HPP_ */
