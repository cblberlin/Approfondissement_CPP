#pragma once

#include "Graphe.hpp"
#include <algorithm>
#include <iterator>

using namespace std;

class Graphe_solveur {
    private:
        Graphe G;
    public:
        // si un tentative de coloration est valide par les contraintes
        bool est_valide(int, int);
        // resoud le problème par backtracking
        void solve_backtracking();
};
