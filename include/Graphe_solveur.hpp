#pragma once

#include "Graphe_colore.hpp"
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;

class Graphe_solveur{
    private:
        Graphe_colore G;
    public:
        Graphe_solveur(Graphe_colore);
        // Renvoie un tableau dont chaque élément correspond au nombre de couleurs disponibles du sommet de même indice du graphe.
        vector<int> tableau_nombre_couleurs_dispos();
        // si un tentative de coloration est valide par les contraintes
        bool est_valide(int, int);
        // resoud le problème par backtracking
        bool solve_backtracking(int);
};
