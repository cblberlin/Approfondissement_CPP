#include <iostream>
#include "Graphe_colore.hpp"
#include "Graphe_solveur.hpp"
#include "Sudoku.hpp"
#include <vector>
#include <string>

using namespace std;

int main(){

    vector< vector<int> > grid{ {0, 0, 0, 1}, {3, 0, 4, 0}, {0, 3, 0, 0}, {2, 0, 0, 0} };
    Sudoku S(grid);
    S.afficher();
    S.afficher_grid();
    
    Graphe_solveur G_solve2(S);
    G_solve2.solve_backtracking();
    S.afficher_grid();
    
    
    //Graphe_solveur G_solve(G);

    //G_solve.solve()
    
    return 0;
}