#include "ListArray.h"


ListArray::ListArray(int capacity)
{
    head = new NodeArray(capacity, nullptr);
    head->setSize(0);
    head->setCapacity(capacity);
}

ListArray::~ListArray()
{
    NodeArray *nodo_actual = head;
    while (nodo_actual != nullptr)
    {
        NodeArray *next_node = nodo_actual->getNext();
        delete nodo_actual;
        nodo_actual = next_node;
    }
}
// Getters
NodeArray* ListArray::getHead() const {
    return head;
}

SummaryNode* ListArray::getRoot() const {
    return root;
}

int ListArray::getSize() const {
    return this->l_size;
}

int ListArray::getCapacity() const {
    return capacity;
}

int ListArray::getActualNodes() const {
    return actual_nodes;
}

// Setters
void ListArray::setHead(NodeArray* head) {
    this->head = head;
}

void ListArray::setRoot(SummaryNode* root) {
    this->root = root;
}

void ListArray::setSize(int size) {
    this->l_size = size;
}

void ListArray::setCapacity(int capacity) {
    this->capacity = capacity;
}

void ListArray::setActualNodes(int actual_nodes) {
    this->actual_nodes = actual_nodes;
}
int ListArray::size()
{
    int total_size = 0;
    NodeArray *nodo_actual = head;
    while (nodo_actual != nullptr)
    {
        total_size += nodo_actual->getSize();
        nodo_actual = nodo_actual->getNext();
    }
    return total_size;
}
void ListArray::insert_left(int v)
{
    insert(0,v);
}

void ListArray::print()
{
    NodeArray *nodo_actual = head;
    while (nodo_actual != nullptr)
    {
        for (int i = 0; i < nodo_actual->getSize(); i++)
        {
            std::cout << nodo_actual->getData()[i] << " ";
        }
        nodo_actual = nodo_actual->getNext();
    }
    std::cout << std::endl;
}

void ListArray::insert_right(int v) {
    insert(l_size-1,v);
}
void ListArray::insert(int v, int i)
{   
    if (actual_nodes != totalNodes())
    {
        createTree();
    }
    
    if (i > getSize())
    {
        throw out_of_range("Indice fuera de rango");
        return;
    }

    SummaryNode* current = arbol.front();
    while (current->getHijo() == nullptr)
    {
        if (current->getLeft()->getSize() >= i)
        {
            current = current->getLeft();
        }
        else
        {
            i = i - current->getLeft()->getSize();
            current = current->getRight();
        }
    }
    current->getHijo()->add(v, i);
}

bool ListArray::find(int v)
{
    NodeArray *nodo_actual = head;
    while (nodo_actual != nullptr)
    {
        for (int i = 0; i < nodo_actual->getSize(); i++)
        {
            if (nodo_actual->getData()[i] == v)
            {   
                cout << "El elemento " << v << " se encuentra en el ListArr" << endl;
                return true;
            }
        }
        nodo_actual = nodo_actual->getNext();
    }
    cout << "El elemento " << v << " NO se encuentra en el ListArr" << endl;
    return false;
}
void ListArray::createTree()
{
    NodeArray* actual = this->getHead();
    arbol.clear();


    while (actual != nullptr)
    {
        SummaryNode* ref = new SummaryNode(actual, actual->getSize(), actual->getCapacity());
        arbol.push_back(ref);
        actual = actual->getNext();
    }
    if(this->getHead()->getNext() == nullptr) arbol.push_back(nullptr);

    while(arbol.size() > 1)
    {
        if(arbol.size() % 2 != 0)
        {
            arbol.push_back(nullptr);
        }
        int maxNodosPerLevel = arbol.size() / 2;
        for(int i = 0; i < maxNodosPerLevel; i++)
        {
            SummaryNode* left = arbol.front();
            arbol.pop_front();
            SummaryNode* right = arbol.front();
            arbol.pop_front();

            if(right == nullptr)
            {
                SummaryNode* padre = new SummaryNode(left, right, left->getSize(), left->getCapacity() * 2);
                arbol.push_back(padre);
                continue;
            }
            SummaryNode* padre = new SummaryNode(left, right, left->getSize() + right->getSize(), left->getCapacity() * 2);
            arbol.push_back(padre);
        }
    }
    setRoot(arbol.front());
    setSize(arbol.front()->getSize());
    setCapacity(arbol.front()->getCapacity());

}
int ListArray::totalNodes()
{
    int count = 0;
    NodeArray *current = head;
    while (current != nullptr)
    {
        count++;
        current = current->getNext();
    }
    return count;
}
