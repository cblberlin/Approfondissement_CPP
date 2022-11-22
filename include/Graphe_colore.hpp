#pragma once

#include "Arete.hpp"
#include <iostream>
#include <fstream>
#include <cassert>
#include <vector>
#include <set>
#include <cmath>
#include <exception>

using namespace std;

class Graphe_colore{
    protected:
        // le nombre du noeud
        int nb_node;

        // le nombre maximale pour le graphe, initialement c'est nb_node
        int max_color;

        // un vector qui contient des arête à partir des noeud i
        vector <Arete> *v_Arete;

        // un set qui contient l'indice de voisins pour noeud i
        set <int> *s_Voisins;

        // un vector qui sauvegarde le couleur coloré pour les noeuds
        vector <int> color;
    public:
        /*
        constructeur par 2 entiers
        
        Entrées:
            int nb_noeud: le nombre de noeud dans le graphe
            int max_color: le nb maximale pour le graphe, initialement est nb_node
        */
        
        Graphe_colore(int, int);
        /*
        constructeur par une matrice d'adjacente

        Entrée:
            vector< vector<int> > M:
                de taille N * N avec que de 0 ou 1, si M(i,j) = 1,
                c'est-à-dire qu'il y a un arete dans noeud i et noeud j
                sinon il n'y a pas
        */
        Graphe_colore( vector< vector<int> >);

        /*
        constructeur par un fichier *.col qui est issue de 
        https://mat.tepper.cmu.edu/COLOR/instances.html
        */
        Graphe_colore(string);

        // destructeur pour libérer le mémoire
        ~Graphe_colore();

        /*
        retourner le nombre de node
        */
        const int get_nb_node() {return nb_node;}

        /*
        retourne le nombre d'arête
        */ 
        const int get_nb_edge();

        /*
        retourne le nombre maximal de couleur pour ce graphe
        */
        const int get_max_color() {return max_color;}

        /*
        ajouter l'arret dans le graphe entre i et j
            int i: noeud i (i >= 0)
            int j: noeud j (j >= 0)
        (par défaut i != j)
        */ 
        void ajout_arete(int, int);

        // retourne le nombre de voisins du noeud i
        const int nb_voisins(int);

        // retourne la liste de voisin du noeud i
        const set<int> voisins(int);

        // afficher le graphe par liste d'adjacente
        void afficher();
        // afficher les arrets
        void afficher_arete();
        // colorer un noeud i par un couleur 
        void colorer(int, int);
        // retourne le nombre de voisin pour noeud i
        const set<int> get_voisins(int);

        // retourne le couleur de noeud i
        const int get_color(int);
        
};