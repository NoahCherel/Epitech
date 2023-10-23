/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** SharedPointer
*/

#ifndef SHAREDPOINTER_HPP_
#define SHAREDPOINTER_HPP_

#include <iostream>
#include <string>
#include <functional>
#include <memory>

template <typename Type>
class SharedPointer {
    public:
        SharedPointer() : _ptr(nullptr), _count(nullptr) {}
        SharedPointer(Type *ptr) : _ptr(ptr), _count(new size_t(1)) {}
        SharedPointer(const SharedPointer &other) : _ptr(other._ptr), _count(other._count) {
            if (_count)
                (*_count)++;
        }
        SharedPointer &operator=(const SharedPointer &other) {
            if (this != &other) {
                if (_count && --(*_count) == 0) {
                    delete _ptr;
                    delete _count;
                }
                _ptr = other._ptr;
                _count = other._count;
                if (_count)
                    (*_count)++;
            }
            return *this;
        }
        SharedPointer(SharedPointer &&other) : _ptr(other._ptr), _count(other._count) {
            other._ptr = nullptr;
            other._count = nullptr;
        }
        SharedPointer &operator=(SharedPointer &&other) {
            if (this != &other) {
                if (_count && --(*_count) == 0) {
                    delete _ptr;
                    delete _count;
                }
                _ptr = other._ptr;
                _count = other._count;
                other._ptr = nullptr;
                other._count = nullptr;
            }
            return *this;
        }
        ~SharedPointer() {
            if (_count && --(*_count) == 0) {
                delete _ptr;
                delete _count;
            }
        }
        Type *get() const { return _ptr; }
        Type *release() {
            Type *tmp = _ptr;
            _ptr = nullptr;
            if (_count && --(*_count) == 0) {
                delete _count;
                _count = nullptr;
            }
            return tmp;
        }
        void reset(Type *ptr = nullptr) {
            if (_count && --(*_count) == 0) {
                delete _ptr;
                delete _count;
            }
            _ptr = ptr;
            _count = new size_t(1);
        }
        Type &operator*() const { return *_ptr; }
        Type *operator->() const { return _ptr; }
        operator bool() const { return _ptr != nullptr; }
    private:
        Type *_ptr;
        size_t *_count;
};

#endif /* !SHAREDPOINTER_HPP_ */
