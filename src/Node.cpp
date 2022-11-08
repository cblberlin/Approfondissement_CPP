#include "Node.hpp"

Node::Node(unsigned nodeid, string col) : id(nodeid), color(col)
{
    this->next = NULL;
}

void Node::add_node(Node * head, unsigned id, string col)
{
    Node *ptr = head;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    Node *p1 = new Node;
    p1->id = id;
    p1->color = col;
    ptr->next = p1;
}