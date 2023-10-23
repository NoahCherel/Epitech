/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Parser
*/

#include "../Include/Parser.hpp"
#include "../Include/Circuit.hpp"

Parser::Parser() {}

void Parser::checkFile(const std::string &filename, std::ifstream &file) {
    if (filename.substr(filename.find_last_of(".") + 1) != "nts") {
        throw std::invalid_argument("Error: invalid file extension");
    }
    if (!file.good()) {
        throw std::invalid_argument("Error: could not open file " + filename);
    }
    if (file.peek() == std::ifstream::traits_type::eof()) {
        throw std::invalid_argument("Error: file " + filename + " is empty");
    }
}

std::vector<std::string> Parser::remove_empty_lines(std::vector<std::string> &lines) {
    for (auto it = lines.begin(); it != lines.end();) {
        if (it->empty()) {
            it = lines.erase(it);
        } else {
            ++it;
        }
    }
    return lines;
}

std::vector<std::string> Parser::remove_comment(std::vector<std::string> &lines) {
    for (auto it = lines.begin(); it != lines.end();) {
        if (it->find('#') != std::string::npos) {
            it = lines.erase(it);
        } else {
            ++it;
        }
    }
    return lines;
}

void Parser::parseFile(const std::string &filename) {

    std::ifstream file(filename);
    std::vector<std::string> lines;
    checkFile(filename, file);
    std::string line;
    while (getline(file, line)) {
        lines.push_back(line);
    }
    lines = remove_empty_lines(lines);
    lines = remove_comment(lines);

    int check_link = 0;
    int check_chipset = 0;

    for (auto it = lines.begin(); it != lines.end(); ++it) {
        if (it->find(".chipsets:") != std::string::npos) {
            check_chipset = 1;
            break;
        }
    }
    if (check_chipset == 0) {
        throw std::invalid_argument("Error: no chipset found");
    }
    for (auto it = lines.begin(); it != lines.end(); ++it) {
        if (it->find(".links:") != std::string::npos) {
            check_link = 1;
            break;
        }
    }
    if (check_link == 0) {
        throw std::invalid_argument("Error: no link found");
    }
    if (file.is_open()) {
        std::string line;
        while (getline(file, line)) {
            parseLine(line);
        }
        file.close();
    } else {
        std::cerr << "Error: could not open file " << filename << std::endl;
    }
}

void Parser::parseLine(const std::string &line) {
    std::vector<std::string> tokens = splitLine(line);
    if (tokens.empty()) {
        return;
    }
    std::string command = tokens[0];
    tokens.erase(tokens.begin());
    if (command == "input") {
        setInput(tokens);
    } else if (command == "output") {
        setOutput(tokens);
    } else if (command == "link") {
        linkComponents(tokens);
    } else {
        addComponent(tokens);
    }
}

std::vector<std::string> Parser::splitLine(const std::string &line) {
    std::vector<std::string> tokens;
    std::string token;
    std::stringstream ss(line);
    while (ss >> token) {
        tokens.push_back(token);
    }
    return tokens;
}

bool Parser::isNumber(const std::string &str) {
    return std::all_of(str.begin(), str.end(), ::isdigit);
}

bool Parser::isAlpha(const std::string &str) {
    return std::all_of(str.begin(), str.end(), ::isalpha);
}

bool Parser::isAlphaNum(const std::string &str) {
    return std::all_of(str.begin(), str.end(), ::isalnum);
}

void Parser::addComponent(const std::vector<std::string> &tokens) {
    if (tokens.size() != 2) {
        std::cerr << "Error: invalid component definition - " << tokens.size() << " tokens found, 2 expected" << std::endl;
        return;
    }
    std::string name = tokens[0];
    std::string type = tokens[1];
    if (!isAlphaNum(name) || !isAlpha(type)) {
        std::cerr << "Error: invalid component definition - name and type must be alphanumeric" << std::endl;
        return;
    }
    if (_components.find(name) != _components.end()) {
        std::cerr << "Error: invalid component definition - component " << name << " already exists" << std::endl;
        return;
    }
    _components[name] = type;
}

void Parser::setInput(const std::vector<std::string> &tokens) {
    if (tokens.size() != 1) {
        std::cerr << "Error: invalid input definition - " << tokens.size() << " tokens found, 1 expected" << std::endl;
        return;
    }
    std::string name = tokens[0];
    if (!isAlphaNum(name)) {
        std::cerr << "Error: invalid input definition - name must be alphanumeric" << std::endl;
        return;
    }
    if (std::find(_inputs.begin(), _inputs.end(), name) != _inputs.end()) {
        std::cerr << "Error: invalid input definition - input " << name << " already exists" << std::endl;
        return;
    }
    _inputs.push_back(name);
}

void Parser::setOutput(const std::vector<std::string> &tokens) {
    if (tokens.size() != 1) {
        std::cerr << "Error: invalid output definition - " << tokens.size() << " tokens found, 1 expected" << std::endl;
        return;
    }
    std::string name = tokens[0];
    if (!isAlphaNum(name)) {
        std::cerr << "Error: invalid output definition - name must be alphanumeric" << std::endl;
        return;
    }
    if (std::find(_outputs.begin(), _outputs.end(), name) != _outputs.end()) {
        std::cerr << "Error: invalid output definition - output " << name << " already exists" << std::endl;
        return;
    }
    _outputs.push_back(name);
}

void Parser::linkComponents(const std::vector<std::string> &tokens) {
    if (tokens.size() != 3) {
        std::cerr << "Error: invalid link definition - " << tokens.size() << " tokens found, 3 expected" << std::endl;
        return;
    }
    std::string name1 = tokens[0];
    std::string pin1 = tokens[1];
    std::string name2 = tokens[2];
    if (!isAlphaNum(name1) || !isNumber(pin1) || !isAlphaNum(name2)) {
        std::cerr << "Error: invalid link definition - name and pin must be alphanumeric" << std::endl;
        return;
    }
    if (_components.find(name1) == _components.end()) {
        std::cerr << "Error: invalid link definition - component " << name1 << " does not exist" << std::endl;
        return;
    }
    if (_components.find(name2) == _components.end()) {
        std::cerr << "Error: invalid link definition - component " << name2 << " does not exist" << std::endl;
        return;
    }
    _links.push_back({tokens[1], tokens[3]});
}

void Parser::displayComponents() const {
    std::cout << "=== Components ===" << std::endl;
    for (auto const& component : _components) {
        std::cout << component.first << ": " << component.second << std::endl;
    }
}

void Parser::displayInputs() const {
    std::cout << "Input(s):" << std::endl;
    for (auto const& input : _inputs) {
        std::cout << input << std::endl;
    }
}

void Parser::displayOutputs() const {
    std::cout << "output(s):" << std::endl;
    for (auto const& output : _outputs) {
        std::cout << output << std::endl;
    }
}

void Parser::displayLinks() const {
    std::cout << "=== Links ===" << std::endl;
    for (auto const& link : _links) {
        std::cout << link.first << " -> " << link.second << std::endl;
    }
}

void Parser::display() const {
    //displayComponents();
    //std::cout << std::endl;
    displayInputs();
    std::cout << std::endl;
    displayOutputs();
    //std::cout << std::endl;
    //displayLinks();
}
