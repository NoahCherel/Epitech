/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** UniquePointer
*/

#ifndef UNIQUEPOINTER_HPP_
#define UNIQUEPOINTER_HPP_

template <typename Type>
class UniquePointer {
    public:
        UniquePointer() : _ptr(nullptr) {}
        UniquePointer(Type *ptr) : _ptr(ptr) {}
        UniquePointer(const UniquePointer &other) = delete;
        UniquePointer &operator=(const UniquePointer &other) = delete;
        UniquePointer(UniquePointer &&other) : _ptr(other._ptr) { other._ptr = nullptr; }
        UniquePointer &operator=(UniquePointer &&other) {
            if (this != &other) {
                delete _ptr;
                _ptr = other._ptr;
                other._ptr = nullptr;
            }
            return *this;
        }
        ~UniquePointer() { delete _ptr; }
        Type *get() const { return _ptr; }
        Type *release() {
            Type *tmp = _ptr;
            _ptr = nullptr;
            return tmp;
        }
        void reset(Type *ptr = nullptr) {
            delete _ptr;
            _ptr = ptr;
        }
        Type &operator*() const { return *_ptr; }
        Type *operator->() const { return _ptr; }
        operator bool() const { return _ptr != nullptr; }
    private:
        Type *_ptr;
};

#endif /* !UNIQUEPOINTER_HPP_ */
