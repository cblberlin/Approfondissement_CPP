#include <iostream>
#include "Sudoku.hpp"
#include "Sudoku_solver.hpp"
#include "Graphe_colore.hpp"
#include <vector>
#include <string>

using namespace std;

int main(){

    // Test 

    
    Graphe_colore G("tests/myciel3.col");
    //cout << "nb node: " << G.get_nb_node() << ", nb edge: " << G.get_nb_edge() << endl;
    G.afficher();
    
    //Graphe_solveur G_solve(G);

    //G_solve.solve()
    
    return 0;
}