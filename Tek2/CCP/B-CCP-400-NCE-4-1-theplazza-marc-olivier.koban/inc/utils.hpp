/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** pizza
*/

#ifndef PIZZA_H_
    #define PIZZA_H_

enum class Type
{
    Regina = 1,
    Margarita = 2,
    Americana = 4,
    Fantasia = 8
};

enum class Size
{
    S = 1,
    M = 2,
    L = 4,
    XL = 8,
    XXL = 16
};

class ErrorHandling : public std::exception
{
public:
    ErrorHandling(const std::string &msg) : errorMessage_(msg) {}
    const char *what() const noexcept override
    {
        return errorMessage_.c_str();
    }

private:
    std::string errorMessage_;
};

struct Order
{
    Type OrderType;
    Size OrderSize;
    int quantity;
};

struct MessageWithOrder
{
    long mtype;
    Order pizza;
};

#endif /* !PIZZA_H_ */
