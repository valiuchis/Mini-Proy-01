#include "SummaryNode.h"
#include <string>

// Constructores
SummaryNode::SummaryNode(SummaryNode *left, SummaryNode *right)
    : left(left), right(right), s_size(0), s_capacity(0), son(nullptr) {
        this->name = "Nodo Resumen " + std::to_string(s_size) + "||" + std::to_string(s_capacity);
    }

SummaryNode::SummaryNode(int s_size, int s_capacity)
    : s_size(s_size), s_capacity(s_capacity), son(nullptr), left(nullptr), right(nullptr) {
        this->name = "Nodo Resumen " + std::to_string(s_size) + "||" + std::to_string(s_capacity);
    }

SummaryNode::SummaryNode(NodeArray *hijo, int s_size, int s_capacity)
    : s_size(0), s_capacity(s_capacity), son(hijo), left(nullptr), right(nullptr) {
        this->name = "Nodo Resumen " + std::to_string(s_size) + "||" + std::to_string(s_capacity);
    }

SummaryNode::SummaryNode(SummaryNode* left, SummaryNode* right, int s_size, int s_capacity)
    : left(left), right(right), s_size(s_size), s_capacity(s_capacity), son(nullptr) {
        this->name = "Nodo Resumen " + std::to_string(s_size) + "||" + std::to_string(s_capacity);
    }

// Destructores
SummaryNode::~SummaryNode() {
    delete son;
}

// Setters
void SummaryNode::setLeft(SummaryNode* left) {
    this->left = left;
}

void SummaryNode::setRight(SummaryNode* right) {
    this->right = right;
}

void SummaryNode::setHijo(NodeArray* hijo) {
    this->son = hijo;
}

void SummaryNode::setSize(int s_size) {
    this->s_size = s_size;
}

void SummaryNode::setCapacity(int s_capacity) {
    this->s_capacity = s_capacity;
}

// Getters
SummaryNode* SummaryNode::getLeft() {
    return left;
}

SummaryNode* SummaryNode::getRight() {
    return right;
}

int SummaryNode::getCapacity() {
    return s_capacity;
}

int SummaryNode::getSize() {
    return s_size;
}

string SummaryNode::getName() {
    return name;
}

NodeArray* SummaryNode::getHijo() {
    return son;
}
