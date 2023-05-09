#pragma once
#include "ListArr.h"
#include <vector>
#include <deque>
class ListArray : public ListArr{
private:
NodeArray* head;
SummaryNode* root;
int l_size;
int capacity;
int actual_nodes;
deque<SummaryNode*> arbol;

public:
ListArray(int capacity);
~ListArray();
int size();                // Retorna la cantidad de elementos almacenados en el ListArr
void insert_left(int v);   // Inserta un nuevo valor v a la izquierda del ListArr. Equivalentemente, inserta el valor v en el índice 0
void insert_right(int v);  // Inserta un nuevo valor v a la derecha del ListArr. Equivalentemente, inserta el valor v en el índice size()-1
void insert(int v, int i); // Inserta un nuevo valor v en el índice i del ListArr.
void print();              // Imprime por pantalla todos los valores almacenados en el ListArr.
bool find(int v);          // Busca en el ListArr si el valor v se encuentra almacenado.
void createTree();
int totalNodes();

// Getter methods
NodeArray *getHead() const;
SummaryNode *getRoot() const;
int getSize() const;
int getCapacity() const;
int getActualNodes() const;

// Setter methods
void setHead(NodeArray *head);
void setRoot(SummaryNode *root);
void setSize(int size);
void setCapacity(int capacity);
void setActualNodes(int actual_nodes);
};
