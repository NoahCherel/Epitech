/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Output
*/

#ifndef OUTPUT_HPP_
#define OUTPUT_HPP_

#include <string>

class Output {
public:
    Output(const std::string& name);

    const std::string& getName();

    bool getValue();
    void setValue(bool value);

private:
    std::string m_name;
    bool m_value;
};


#endif /* !OUTPUT_HPP_ */
