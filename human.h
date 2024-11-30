#pragma once
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <io.h>

using namespace std;

template <typename T>

class Queue 
{
private:
    struct Node 
    {
        T data;
        Node* next;
        Node* prev;

        Node(const T& dataP) : data(dataP), next(nullptr), prev(nullptr) {}
    };

    Node* go;
    Node* beck;
    size_t size;

public:
    Queue() : go(nullptr), beck(nullptr), size(0) {}

    void add_queue(const T& value)
    {
        Node* newNode = new Node(value);

        if (go == nullptr) 
        {
            go = beck = newNode;
        }
        else
        {
            beck->next = newNode;
            newNode->prev = beck;
            beck = newNode;
        }

        size++;
    }

    void print_queue()
    {
        if (go == nullptr) 
        {
            cout << "Очередь пуста.\n Невозможно вывести.";
    
            return;
        }

        Node* temp = go;
        go = go->next;

        if (go == nullptr)
        {
            beck = nullptr;
        }
        else
        {
            go->prev = nullptr;
        }

        delete temp;
        size--;
    }

    T front() const
    {
        if (go == nullptr) 
        {
            throw runtime_error("Очередь пустая\n");
        }
        return go->data;
    }

    bool empty() const{ return size == 0; }

    size_t getSize() const { return size;}

    ~Queue() 
    {
        while (go != nullptr) 
        {
            Node* temp = go;
            go = go->next;
            delete temp;
        }
    }
};
