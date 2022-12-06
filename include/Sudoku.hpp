#pragma once

#include "Graphe_colore.hpp"

#include <iostream>
#include <fstream>
#include <vector>
#include <cassert>
#include <string>

using namespace std;

class Sudoku : public Graphe_colore{
    private:
        // le grid de sudoku
        vector<vector<int> > grid;
    public:
        // constructeur par une matrice
        Sudoku(vector<vector<int> >);
 
        // constructeur par un fichier
        Sudoku(string nom_fichier);
        
        // afficher le grid
        void afficher_grid();
};
