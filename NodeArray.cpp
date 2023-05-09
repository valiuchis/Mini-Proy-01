
#include "NodeArray.h"

// Constructor 
NodeArray::NodeArray(int capacity, NodeArray *next)
    : size(0), capacity(capacity), data(new int[capacity]), next(next) {}

// Destructor 
NodeArray::~NodeArray() {
    delete[] data;
}

// Getter 
int NodeArray::getSize() {
    return this->size;
}

int NodeArray::getCapacity(){
    return this->capacity;
}

int* NodeArray::getData() {
    return this->data;
}

NodeArray* NodeArray::getNext(){
    return this->next;
}

// Setter 
void NodeArray::setSize(int size) {
    this->size = size;
}

void NodeArray::setCapacity(int capacity) {
    this->capacity = capacity;
}

void NodeArray::setData(int index, int value) {
    if (index >= 0 && index < capacity) {
        data[index] = value;
    }
}

void NodeArray::setNext(NodeArray* next) {
    this->next = next;
}
bool NodeArray::isFull() const {
    return size == capacity;
}
void NodeArray::add(int v, int indice) {
    if (isFull()) {
        if (next == nullptr || next->isFull()) {
            NodeArray* newNode = new NodeArray(*next);
            setNext(newNode);
        }
        next->add(0, data[size - 1]);
    }

    for (int i = size; i > indice; i--) {
        data[i] = data[i - 1];
    }
    data[indice] = v;

    if (!isFull()) {
        size++;
    }
}