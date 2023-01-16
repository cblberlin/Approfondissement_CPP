#include "Sudoku.hpp"

Sudoku::Sudoku(vector<vector<int> > Grid) : Graphe_colore(Grid.size()*Grid.size(), Grid.size()){
    assert(Grid.size() == Grid[0].size());
    grid = Grid;
    result = Grid;
    int n = Grid.size();
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

            // ajoute arete pour colonne
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
    for(size_t i = 0; i < grid.size(); i++){
        for(size_t j = 0; j < grid.size(); j++){
            if(sol){
                result[i][j] = color[i*grid.size()+j] + 1;
            }
            cout << color[i*grid.size()+j] + 1 << " ";
        }
        cout << endl;
    }
}

void Sudoku::afficher_result(){
    if (!sol){
        cout << "ce sudoku n'a pas de solution" << endl;
        return;
    }
    cout << "la solution de sudoku est:\n";
    for(size_t i = 0; i < grid.size(); i++){
        for(size_t j = 0; j < grid.size(); j++){
            if(sol){
                result[i][j] = color[i*grid.size()+j] + 1;
            }
            cout << color[i*grid.size()+j] + 1 << " ";
        }
        cout << endl;
    }
}