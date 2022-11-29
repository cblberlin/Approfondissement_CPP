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
        // si un tentative de coloration est valide par les contraintes
        bool est_valide(int, int);
        // resoud le problème par backtracking
        bool solve_backtracking(int);
};
