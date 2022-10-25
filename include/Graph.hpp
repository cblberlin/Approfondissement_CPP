#pragma once
#include <cassert>
#include <cmath>

/*
La class pour représenter un graph par une matrice d'adjacente
*/

class Graph{
    private:
        int nb_noeud;
        int** nb_arret;
    public:
        Graph(){}
        Graph(int n):nb_noeud(n){}
        ~Graph(){}
};

