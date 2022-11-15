#pragma once
#include "Node.hpp"
#include "Arret.hpp"
#include <iostream>
#include <list>

using namespace std;

class Graphe{
    private:
        list <Arret> Liste;
        int nb_node;
        int max_color;
    public:
        // constructeur
        Graphe(int _nb_node, int _max_color) : nb_node(), max_color(_max_color){};
        // return le nombre de noeud
        int get_nb_node() {return nb_node;}
        // return le nombre maximal de couleur pour ce graphe
        int get_max_color() {return max_color;}
        // ajouter l'arret dans le graphe
        void ajout_arret(Node n1, Node n2);
};