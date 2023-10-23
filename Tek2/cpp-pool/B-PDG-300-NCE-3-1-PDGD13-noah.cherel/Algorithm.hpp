/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Algorithm
*/

#ifndef ALGORITHM_HPP_
#define ALGORITHM_HPP_

#include <iostream>
#include <string>
#include <algorithm>
#include <functional>

template <typename T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
const T& min(const T& a, const T& b) {
    return std::min(a, b);
}

template <typename T>
const T& max(const T& a, const T& b) {
    return std::max(a, b);
}

template <typename T>
const T& clamp(const T& value, const T& minValue, const T& maxValue) {
    return std::min(std::max(value, minValue), maxValue);
}

#endif /* !ALGORITHM_HPP_ */
