#pragma once
#include <string>

using namespace std;

class Node{
    private:
        unsigned id;
        string color;
        Node * next;
    public:
        Node(unsigned, string);
        void add_node(Node *head, unsigned id, string col);

};