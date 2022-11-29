#include <iostream>
#include "Graphe_colore.hpp"
#include <vector>
#include <string>

using namespace std;

int main(){

    // Test pour le constructeur par 2 int
    Graphe_colore G1(5, 5);
    

    
    Graphe_colore G3("tests/myciel3.col");
    //cout << "nb node: " << G.get_nb_node() << ", nb edge: " << G.get_nb_edge() << endl;
    G3.afficher();
    
    //Graphe_solveur G_solve(G);

    //G_solve.solve()
    
    return 0;
}