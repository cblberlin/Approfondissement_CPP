#include "Sudoku.hpp"

Sudoku::Sudoku(vector<vector<int> > Grid) : Graphe_colore(Grid.size()*Grid.size(), Grid.size()){
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
            ajout_arete(i*n + j, )
        }
    }

}



void Sudoku::afficher_grid(){
    cout << "le grid de sudoku est:\n";
    for(int i = 0; i < nb_node; i++){
        for(int j = 0; j < nb_node; j++){
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

