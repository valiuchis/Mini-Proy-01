#pragma once 
#include "NodeArray.h"
using namespace std;

class SummaryNode {
    private:
        int s_size;
        int s_capacity;
        string name;
        NodeArray* son;
        SummaryNode* left;
        SummaryNode* right;
    public:
    SummaryNode (SummaryNode *left, SummaryNode *right);
    SummaryNode (int s_size, int s_capacity);
    SummaryNode (NodeArray *hijo, int s_size, int s_capacity);
    SummaryNode(SummaryNode* left, SummaryNode* right, int s_size, int s_capacity);
    ~SummaryNode();
    void setLeft(SummaryNode* left);
    void setRight(SummaryNode* right);
    void setHijo(NodeArray* hijo);
    void setSize(int s_size);
    void setCapacity(int s_capacity);
    
    SummaryNode* getLeft();
    SummaryNode* getRight();
    int getCapacity();
    int getSize();
    string getName();
    NodeArray* getHijo();

};