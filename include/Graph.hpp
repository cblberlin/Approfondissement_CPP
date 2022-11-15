#pragma once

#include "Arret.hpp"
#include <iostream>
#include <list>

using namespace std;

class Graphe{
    private:
        list <Arret> *Liste;
        int nb_node;
        int max_color;
    public:
        // constructeur
        Graphe(int, int);
        // return le nombre de noeud
        int get_nb_node() {return nb_node;}
        // return le nombre maximal de couleur pour ce graphe
        int get_max_color() {return max_color;}
        // ajouter l'arret dans le graphe
        void ajout_arret(int n1, int n2);
};