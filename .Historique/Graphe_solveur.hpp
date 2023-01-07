#pragma once

#include "Graphe.hpp"
#include <algorithm>
#include <iterator>

using namespace std;

class Graphe_solveur : public Graphe{
    public:
        // Renvoie un tableau dont chaque élément correspond au nombre de voisins du sommet de même indice du graphe.
        vector<int> tableau_nombre_voisins(){
            int n = s_Voisins.size();
            vector<int> resultat [n];
            for(int i = 0; i < n; i++) {
                resultat[i] = nb_voisins(i);
            }
            return resultat;
        }
        // Renvoie un tableau dont chaque élément correspond au nombre de couleurs disponibles du sommet de même indice du graphe.
        vector<int> tableau_nombre_couleurs_dispos();
        // si un tentative de coloration est valide par les contraintes
        bool est_valide(int, int);
        // résoud le problème par backtracking
        bool solve_backtracking(vector<int> &, vector<int> &);
        void printResult();
};