#include <iostream>
#include "Sudoku.hpp"
#include "Sudoku_solver.hpp"
#include "Graphe.hpp"
#include <vector>
#include <string>

using namespace std;

int main(){

    // test pour constructeur vide
    

    // test pour constructeur par tableau
    
    /*
    
    
    
    int grid[9][9] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},
                      {0, 5, 0, 0, 9, 0, 6, 0, 0}, 
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};

    Sudoku s(9);
    //cout << "sudoku is " << endl;
    s.setGrid(grid);

    s.print_grid();
    cout << endl << endl;
    // test for assign
    //s(0,1) = 1;
    //cout << "sudoku is " << endl;
    s.print_grid();

    Sudoku_solver solver;

    if(solver.solve_backtracking(s, 0, 0)){
        s.print_grid();
    }
    */
    /*
    vector<vector<int> > Grid{
        {3, 0, 6, 5, 0, 8, 4, 0, 0},
        {5, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 8, 7, 0, 0, 0, 0, 3, 1},
        {0, 0, 3, 0, 1, 0, 0, 8, 0},
        {9, 0, 0, 8, 6, 3, 0, 0, 5},
        {0, 5, 0, 0, 9, 0, 6, 0, 0}, 
        {1, 3, 0, 0, 0, 0, 2, 5, 0},
        {0, 0, 0, 0, 0, 0, 0, 7, 4},
        {0, 0, 5, 2, 0, 6, 3, 0, 0}
        };
    //cout << "test for constructor" << endl;
    Graphe G(Grid);
    //cout << "test for print" << endl;
    */
    Graphe G("tests/myciel3.col");
    //cout << "nb node: " << G.get_nb_node() << ", nb edge: " << G.get_nb_edge() << endl;
    G.afficher();
    
    return 0;
}