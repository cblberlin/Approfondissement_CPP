#pragma once

#include "Graph.hpp"
#include <algorithm>

class Graphe_solveur : public Graphe {
    public:
        // si un tentative de coloration est valide par les contraintes
        bool est_valide(int, int);
        // resoud le problème par backtracking
        void solve(int);
};