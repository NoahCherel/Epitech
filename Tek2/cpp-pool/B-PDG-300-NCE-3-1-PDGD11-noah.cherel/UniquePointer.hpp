/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** UniquePointer
*/

#ifndef UNIQUEPOINTER_HPP_
#define UNIQUEPOINTER_HPP_

#include "IObject.hpp"
#include <iostream>
#include <string>

class UniquePointer {
    public:
        UniquePointer() : m_ptr(nullptr) {};
        UniquePointer(IObject *ptr) : m_ptr(ptr) {};
        ~UniquePointer() {
            if(m_ptr)
                delete m_ptr;
        }
        IObject* operator->() { return m_ptr; }
        IObject& operator*() { return *m_ptr; }
        UniquePointer &operator=(IObject *ptr) {
            if(m_ptr)
                delete m_ptr;
            m_ptr = ptr;
            return *this;
        }
        void reset(IObject *ptr) {
            if(m_ptr)
                delete m_ptr;
            m_ptr = ptr;
        }
        void reset() {
            if(m_ptr)
                delete m_ptr;
            m_ptr = nullptr;
        }
        void swap(UniquePointer &uniquePointer) {
            IObject* temp = uniquePointer.m_ptr;
            uniquePointer.m_ptr = m_ptr;
            m_ptr = temp;
        }
    private:
        IObject *m_ptr;
};


#endif /* !UNIQUEPOINTER_HPP_ */
