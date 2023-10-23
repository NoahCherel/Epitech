/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Assistant
*/

#ifndef ASSISTANT_HPP_
#define ASSISTANT_HPP_

#include "Student.hpp"
#include "Dean.hpp"
#include <iostream>
#include <string>
#include <fstream>

class Assistant {
    public:
        Assistant(int id) : id_(id), working_(false) {
            std::cout << "Assistant " << id_ 
            << ": 'morning everyone *sip coffee*" << std::endl;
        }
        ~Assistant() {
            std::cout << "Assistant " << id_ 
            << ": see you tomorrow at 9.00 *sip coffee*" << std::endl;
        }
        void giveDrink(Student* student, std::string drink) {
            std::cout << "Assistant " << id_ 
            << ": drink this, " << student->getName() 
            << " *sip coffee*" << std::endl;
            student->drink(drink);
        }
        std::string readDrink(std::string studentName) {
            std::string fileName = studentName + ".drink";
            std::ifstream file(fileName);
            if (file.good()) {
                std::string drink;
                file >> drink;
                std::cout << "Assistant " << id_ << ": " 
                << studentName << " needs a " << drink 
                << " *sip coffee*" << std::endl;
                file.close(); std::remove(fileName.c_str()); return drink;
            }
            return "";
        }
        void helpStudent(Student* student) {
            std::string drink = readDrink(student->getName());
            if (!drink.empty()) {
                giveDrink(student, drink);
            } else {
                std::cout << "Assistant " << id_ << ": " << 
                student->getName() << " seems fine *sip coffee*" << std::endl;
            }
        }
        void timeCheck() {
            if (!working_) {
                std::cout << "Assistant " << id_ 
                << ": Time to teach some serious business *sip coffee*" 
                << std::endl;
                working_ = true;
            } else {
                std::cout << "Assistant " << id_ 
                << ": Enough teaching for today *sip coffee*" << std::endl;
                working_ = false;
            }
        }
    private:
        int id_;
        bool working_;
};

#endif /* !ASSISTANT_HPP_ */
