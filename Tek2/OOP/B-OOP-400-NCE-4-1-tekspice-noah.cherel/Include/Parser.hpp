/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** IParser
*/

#ifndef PARSER_HPP_
#define PARSER_HPP_

#include <fstream>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>
#include <string>
#include <unordered_map>

#include "Circuit.hpp"

class Parser {
public:
    Parser();
    ~Parser() = default;
    void parseFile(const std::string &filename);
    void parseLine(const std::string &line);
    std::vector<std::string> splitLine(const std::string &line);
    bool isNumber(const std::string &str);
    bool isAlpha(const std::string &str);
    bool isAlphaNum(const std::string &str);
    void addComponent(const std::vector<std::string> &tokens);
    void setInput(const std::vector<std::string> &tokens);
    void setOutput(const std::vector<std::string> &tokens);
    void linkComponents(const std::vector<std::string> &tokens);
    void displayComponents() const;
    void displayInputs() const;
    void displayOutputs() const;
    void displayLinks() const;
    void display() const;
    void checkFile(const std::string &filename, std::ifstream &file);
    std::vector<std::string> remove_comment(std::vector<std::string> &lines);
    std::vector<std::string> remove_empty_lines(std::vector<std::string> &lines);
    std::map<std::string, std::string> _components;
    std::vector<std::string> _inputs;
    std::vector<std::string> _outputs;
    std::vector<std::pair<std::string, std::string>> _links;
};


#endif // PARSER_HPP
