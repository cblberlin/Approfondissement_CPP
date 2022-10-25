#pragma once
#include <cassert>
#include <cmath>
#include <vector>

using namespace std;

/*
La class pour représenter un graph par une matrice d'adjacente
*/

class Graph{
    private:
        int nb_noeud;
        vector<vector<int> > M_adj;
    public:
        Graph(int);
        ~Graph(){};
        int size() {return nb_noeud;}
        void print_graph();
};

