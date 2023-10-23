/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Array
*/

#ifndef ARRAY_HPP_
#define ARRAY_HPP_

#include <iostream>
#include <string>
#include <functional>

template <typename Type, size_t Size>
    class Array {
    public:
    Array() {
        for (size_t i = 0; i < Size; i++)
            _array[i] = Type();
    }
    std::size_t size() const { return Size; }
    Type &operator[](size_t index) {
        if (index >= Size)
            throw std::out_of_range("Out of range");
        return _array[index];
    }
    const Type &operator[](size_t index) const {
        if (index >= Size)
            throw std::out_of_range("Out of range");
        return _array[index];
    }
    template <typename NewType>
    Array<NewType, Size> convert(const std::function<NewType(const Type &)> &func) const {
        Array<NewType, Size> newArray;
        for (size_t i = 0; i < Size; i++)
            newArray[i] = func(_array[i]);
        return newArray;
    }
    void forEach(const std::function<void(const Type &)> &func) const {
        for (size_t i = 0; i < Size; i++)
            func(_array[i]);
    }
    private:
        Type _array[Size];
    };

template <typename T, size_t N>
std::ostream &operator<<(std::ostream &os, const Array<T, N> &array) {
    os << "[";
    for (size_t i = 0; i < N; i++) {
        os << array[i];
        if (i != N - 1)
            os << ", ";
    }
    os << "]";
    return os;
}

#endif /* !ARRAY_HPP_ */
