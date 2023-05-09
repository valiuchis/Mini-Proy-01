#pragma once
#include <iostream>


class NodeArray {
    private:
        int size;
        int capacity;
        int *data;
        NodeArray *next;

    public:
        NodeArray (int capacity, NodeArray *next);
        ~NodeArray();

        int getSize();
        int getCapacity();
        int* getData();
        NodeArray* getNext();

        void setSize(int size);
        void setCapacity(int capacity);
        void setData(int index, int value);
        void setNext(NodeArray* next);
        bool isFull() const;
        void add(int v, int indice);
};
