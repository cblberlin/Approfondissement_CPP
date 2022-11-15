#include "Graph.hpp"

Graphe::~Graphe(){
    delete [] Liste;
}

Graphe::Graphe(int _nb_node, int _max_color) : nb_node(_nb_node), max_color(_max_color){
    Liste = new list<Arret>[nb_node];
}

void Graphe::ajout_arret(int n1, int n2){
    Liste[n1].push_back(Arret(n1, n2));
    Liste[n2].push_back(Arret(n2, n1));
}