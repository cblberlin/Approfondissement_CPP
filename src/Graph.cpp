#include "Graph.hpp"

// contructeur par défaut qui alloué le mémoire pour le graphe
// et l'initialiser tous 0
Graph::Graph(int n)
{
    nb_noeud = n;
    vector< vector<int> > M_adj;
    for(int i = 0; i < n; i++){
        vector<int> v(n);
        M_adj.push_back(v);
    }
}

