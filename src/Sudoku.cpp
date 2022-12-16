#include "Sudoku.hpp"

Sudoku::Sudoku(vector<vector<int> > Grid) : Graphe_colore(Grid.size()*Grid.size(), Grid.size()){
    assert(Grid.size() == Grid[0].size());
    grid = Grid;
    int n = Grid.size();
    cout << n<< endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int u = i*n + j;

            if(Grid[i][j] != 0){
                colorer(u, Grid[i][j] - 1);
            }
            
            // ajoute arete pour ligne
            for(int k = 0; k < n; k++){
                if(k == j) continue;
                int v = i*n + k;
                ajout_arete(u, v);
            }

            // ajoute arete pour colone
            for(int k = 0; k < n; k++){
                if(k == i) continue;
                int v = k*n + j;
                ajout_arete(u, v);
            }

            // ajoute arete pour box
            int box = (int)sqrt(n);
            int ligne = i / box;
            int col = j / box;
            for(int k = 0; k < box; k++){
                for(int l = 0; l < box; l++){
                    int x = ligne * box + k;
                    int y = col * box + l;
                    if( x == i && y == j) continue;
                    int v = x * n + y;
                    ajout_arete(u, v);
                }
            }
        }
    }
}



void Sudoku::afficher_grid(){
    cout << "le grid de sudoku est:\n";
    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid.size(); j++){
            cout << color[i*grid.size()+j] + 1 << " ";
        }
        cout << endl;
    }
}

