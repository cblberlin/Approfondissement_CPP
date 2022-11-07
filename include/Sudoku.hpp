#pragma once
#include <cassert>
#include <cmath>
#include <vector>
#include <set>
#include <iostream>

using namespace std;
/*
La classe pour représenter un sudoku
*/

class Sudoku{
    private:
        int size;
        int **grid;
    public:
        /*
        constructeur un sudoku de taille NxN l'initialiser par tous 0
        */ 
        Sudoku(int N);
        /*
        destructeur
        */
        ~Sudoku();
        /*
        afficher le grid
        */
        void print_grid();

    /*
    
        Sudoku(int n);
        Sudoku(int** grid);
        int*** grid() {return Grid;}
        void print_sudoku();
        bool est_valide_ligne(int, int, int);
        bool est_valide_col(int, int, int);
        bool est_valide_carre(int, int, int);
        bool est_valide(int, int, int);

    */
};

