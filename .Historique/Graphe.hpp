
291 sur 1 583
C++

Damian Bimbenet <damian.bimbenet@gmail.com>
Pièces jointes
22 nov. 2022 13:38
À CAI, Mohamed

Voici les dernières mises à jour.


5
 pièces jointes
  • Analyse effectuée par Gmail
#pragma once

#include "Arrete.hpp"
#include <iostream>
#include <fstream>
#include <cassert>
#include <vector>
#include <set>
#include <cmath>
#include <exception>

using namespace std;

class Graphe{
    protected:
        int nb_node;
        int max_color;
        vector <Arrete> * v_Arrete;
        set <int> *s_Voisins;
        vector <int> color;
    public:
        // constructeur
        Graphe(int, int);
        // constructeur à partir un vector<vector>
        Graphe( vector< vector<int> >);
        // constructeur à partir un fichier.col
        Graphe(string);
        // destructeur
        ~Graphe();
        // return le nombre de noeud
        int get_nb_node() {return nb_node;}
        // return le nombre d'arret
        int get_nb_edge();
        // return le nombre maximal de couleur pour ce graphe
        int get_max_color() {return max_color;}
        // ajouter l'arret dans le graphe
        void ajout_arrete(int, int);
        // retourne le nombre de voisins du noeud i
        int nb_voisins(int);
        // retourne la liste de voisin du noeud i
        set<int> voisins(int);
        // afficher le graphe par liste d'adjacente
        void afficher();
        // afficher les arrets
        void afficher_arrete
        ();
        // colorer un noeud i par un couleur 
        void colorer(int, int); 
        
};