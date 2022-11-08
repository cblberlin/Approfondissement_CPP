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
        int size;      // le taille N de sudoku 
        int **grid;    // un tableau de taille NxN
        int **immutable;  // un tableau qui contient des chiffres qui est deja rempli dans le grid et ne peut pas etre modifie
    public:
        /*
        constructeur pour un sudoku de taille NxN l'initialiser par tous 0
        */ 
        Sudoku(int N);
        
        /*
        destructeur
        */
        ~Sudoku();
        /*
        return size
        */
        int getSize() {return size;}
        /*
        afficher le grid
        */
        void print_grid();
        /*
        operateur pour recuperer la valeur d'une case
        */
        //int operator() (int, int);
        /*
        operateur pour assigner une valeur a une case
        */
        int & operator() (int, int);  
        /*
        verifier si la case est mutable ou pas
        */
        bool checkImmutable(int, int);
        /*
        creer un tableau d'example sur wikipedia pour tester l'algo
        */
        void setGrid(int g[9][9]);

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

