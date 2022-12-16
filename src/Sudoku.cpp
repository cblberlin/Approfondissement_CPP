#include "Sudoku.hpp"
#include <cmath>

using Graphe_colore::Graphe_colore;

Sudoku::Sudoku(vector<vector<int> > Grid) : Graphe_colore(Grid.size()*Grid.size(), Grid.size()){
    assert(Grid.size() == Grid[0].size());
    grid = Grid;
    int n = Grid.size();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(Grid[i][j] != 0){
                color[n*i + j] = Grid[i][j];
            }
            color[n*i + j] = -1
            int quotient_int_row  = i/int(sqrt(n));     // Mathématiquement, sqrt(n) est un entier.
            int modulo_row = i%int(sqrt(n));            // Mais ça n'est pas le cas "informatiquement".
            int quotient_int_col = j/int(sqrt(n));
            int modulo_col = j%int(sqrt(n));
            // Ajout d'arête avec les élts du même bloc.
            for(int k = quotient_int_row*int(sqrt(n); k < (quotient_int_row+1)*int(sqrt(n)); k++) {
                for(int l = quotient_int_col*int(sqrt(n)); l < (quotient_int_col+1)*int(sqrt(n)); l++) {
                    if(k != i && l != j) {
                        ajout_arete(n*i + j, n*k + l);
                    }
                }
            }
            // Ajout d'arête avec les élts sur la même ligne.
            for(int kk = 0; kk < n; kk++) {
                if(kk < quotient_int_row*int(sqrt(n)) && kk >= (quotient_int_row+1)*int(sqrt(n))) {
                    ajout_arete(n*i + j, n*kk + j);
                }
            }
            // Ajout d'arête avec les élts sur la même colonne.
            for(int ll = 0; ll < n; ll++) {
                if(ll < quotient_int_col*int(sqrt(n)) && ll >= (quotient_int_col+1)*int(sqrt(n))) {
                    ajout_arete(n*i + j, n*i + ll);
                }
            }
            //ajout_arete();
            //ajout_arete();
        }
    }
}

/*Sudoku::Sudoku(vector<vector<int> > Grid) : Graphe_colore(Grid.size()*Grid.size(), Grid.size()){
    assert(Grid.size() == Grid[0].size());
    //using Graphe_colore::Graphe_colore;
    grid = Grid;
    int n = Grid.size();
    for(int i = 0; i < n*n; i++){
        for(int j = 0; j < n*n - 1; j++){
            // ajouter les couleurs pour les cases sont déjà remplis
            if(Grid[i][j] != 0){
                color[i*n + j] = Grid[i][j];
            }
            // sinon c'est -1
            color[i*n + j] = -1;

            // ajoute arete pour ligne
            ajout_arete(i*n + j, j)
            // ajoute arête pour colonne
            ajout_arete())
        }
    }

}*/



void Sudoku::afficher_grid(){
    cout << "le grid de sudoku est:\n";
    for(int i = 0; i < nb_node; i++){
        for(int j = 0; j < nb_node; j++){
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}