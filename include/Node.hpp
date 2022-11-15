#pragma once

using namespace std;

class Node{
    private:
        int id; // l'indice du Node
        int color;   // le couleur du Node
    public:
        // constructeur
        Node(int _id, int _color) : id(_id), color(_color) {}     
};