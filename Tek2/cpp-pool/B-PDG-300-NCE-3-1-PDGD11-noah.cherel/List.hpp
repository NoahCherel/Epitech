/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** List
*/

#ifndef LIST_HPP_
#define LIST_HPP_


#include "IObject.hpp"
#include <stdexcept>

class List
{
    public:
        class InvalidOperationException : public std::exception
        {};

    private:
        class Node
        {
            public:
                IObject* data;
                Node* next;
                Node* prev;
                Node(IObject* obj) : data(obj), next(nullptr), prev(nullptr) {}
                ~Node()
                {
                    delete data;
                }
        };
        Node* head;
        Node* tail;
        std::size_t m_size;

    public:
        List() : head(nullptr), tail(nullptr), m_size(0) {}
        ~List()
        {
            clear();
        }

        bool empty() const
        {
            return m_size == 0;
        }

        std::size_t size() const
        {
            return m_size;
        }

        IObject*& front()
        {
            if (empty())
                throw InvalidOperationException();
            return head->data;
        }

        IObject* front() const
        {
            if (empty())
                throw InvalidOperationException();
            return head->data;
        }

        IObject*& back()
        {
            if (empty())
                throw InvalidOperationException();
        }
        IObject* back() const
        {
            if (empty())
                throw InvalidOperationException();
            return tail->data;
        }
        void pushFront(IObject* obj)
        {
            Node* node = new Node(obj);
            if (empty())
            {
                head = node;
                tail = node;
            }
            else
            {
                node->next = head;
                head->prev = node;
                head = node;
            }
            m_size++;
        }
        void pushBack(IObject* obj)
        {
            Node* node = new Node(obj);
            if (empty())
            {
                head = node;
                tail = node;
            }
            else
            {
                node->prev = tail;
                tail->next = node;
                tail = node;
            }
            m_size++;
        }
        void popFront()
        {
            if (empty())
                throw InvalidOperationException();
            Node* node = head;
            head = head->next;
            if (head)
                head->prev = nullptr;
            else
                tail = nullptr;
            delete node;
            m_size--;
        }
        void popBack()
        {
            if (empty())
                throw InvalidOperationException();
            Node* node = tail;
            tail = tail->prev;
            if (tail)
                tail->next = nullptr;
            else
                head = nullptr;
            delete node;
            m_size--;
        }
        void clear()
        {
            while (!empty())
                popFront();
        }
        void forEach(void (*func)(IObject*))
        {
            Node* node = head;
            while (node)
            {
                func(node->data);
                node = node->next;
            }
        }
};

#endif /* !LIST_HPP_ */
