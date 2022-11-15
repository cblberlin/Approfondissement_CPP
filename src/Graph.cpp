#include "Graph.hpp"

void Graphe::ajout_arret(Node n1, Node n2){
    Liste.push_back(Arret(n1, n2));
    Liste.push_back(Arret(n2, n1));
}