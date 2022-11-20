#pragma once

#include "Arret.hpp"
#include <iostream>
#include <cassert>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

class Graphe{
    private:
        int nb_node;
        int max_color;
        vector <Arret> * v_Arret;
        set <int> *s_Voisins;
        vector <int> color;
    public:
        // constructeur
        Graphe(int, int);
        // constructeur à partir un vector<vector>
        Graphe( vector< vector<int> >);
        // destructeur
        ~Graphe();
        // return le nombre de noeud
        int get_nb_node() {return nb_node;}
        // return le nombre maximal de couleur pour ce graphe
        int get_max_color() {return max_color;}
        // ajouter l'arret dans le graphe
        void ajout_arret(int, int);
        // retourne le nombre de voisins du noeud i
        int nb_voisins(int);
        // retourne la liste de voisin du noeud i
        set<int> voisins(int);
        // afficher le graphe par liste d'adjacente
        void afficher();
};