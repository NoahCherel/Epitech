/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Toy
*/

#ifndef TOY_HPP_
#define TOY_HPP_

#include "Picture.hpp"
#include <string>

class Toy {
    public:
        Toy();
        ~Toy();
        enum ToyType {
            BASIC_TOY,
            ALIEN,
            BUZZ,
            WOODY
        };
        ToyType getType() const;
        std::string getName() const;
        void setName(std::string name);
        bool setAscii(std::string file);
        std::string getAscii() const;
        Toy(ToyType type, std::string name, std::string file);
        Toy(Toy const &toy);
        Toy &operator=(Toy const &toy);
        Toy &operator<<(std::string const &str);
        void speak(std::string const &str);
        bool speak_es(std::string const &str);
        class Error {
        public:
        enum ErrorType { UNKNOWN, PICTURE, SPEAK };
        ErrorType type;
        Error() : type(UNKNOWN), _where(""), _what("") {}
        Error(const char* what, const char* where, ErrorType type) : _what(what), _where(where), type(type) {}
        Error(ErrorType type, std::string const &where, std::string const &what) : type(type), _where(where), _what(what) {}
        std::string where() const { return _where; }
        std::string what() const { return _what; }
        void setType(ErrorType type) { this->type = type; }
        void setWhere(std::string const &where) { _where = where; }
        void setWhat(std::string const &what) { _what = what; }
        private:
        std::string _where;
        std::string _what;
        };
        const Error &getLastError() const { return lastError; }
        void setLastError(const Error &error) { lastError = error; }
        Error lastError;
    protected:
        ToyType type;
        std::string name;
        Picture picture;
};

std::ostream &operator<<(std::ostream &os, Toy const &toy);

#endif /* !TOY_HPP_ */
