#include "Sudoku.hpp"

Sudoku::Sudoku(int N)
{
    size = N;
    grid = new int*[size];
    immutable = new int*[size];
    for(int i = 0; i < size; i++){
        grid[i] = new int[size];
        immutable[i] = new int[size];
    }
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            grid[i][j] = 0;
        }
    }
}

Sudoku::~Sudoku()
{
    for(int i = 0; i < size; i++){
        delete [] grid[i];
        delete [] immutable[i];
    }
    delete [] grid;
    delete [] immutable;
}

void Sudoku::print_grid()
{
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

int & Sudoku::operator() (int i, int j)
{
    assert(0 <= i && size > i && 0 <= j && size > j);
    return grid[i][j];
}

bool Sudoku::checkImmutable(int i, int j)
{
    return immutable[i][j];
}

void Sudoku::setGrid(int g[9][9])
{
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            (*this)(i, j) = g[i][j];
        }
    }
}
/*


// constructeur par défaut qui alloué le mémoire pour le graphe
// et l'initialiser tous 0
Sudoku::Sudoku(int n)
{
    size = n;
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            Grid[i][j] = 0;
        }
    }
}

// constructeur à partir d'un tableau
Sudoku::Sudoku(int grid[N][N])
{
    size = N;
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            Grid[i][j] = grid[i][j];
        }
    }
}

// afficher le sudoku dans le terminal
void Sudoku::print_sudoku()
{
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            cout << Grid[i][j] << " ";
        }
        cout << endl;
    }
}

bool Sudoku::est_valide_ligne(int n, int m, int num)
{
    for(int i = 0; i < 9; i++){
        if(Grid[n][i] == num){
            return false;
        }
    }
    return true ;
}

bool Sudoku::est_valide_col(int n, int m, int num)
{
    for(int i = 0; i < 9; i++){
        if(Grid[i][m] == num){
            return false;
        }
    }
    return true ;
}

bool Sudoku::est_valide_carre(int n, int m, int num)
{
    int ligne_debut = n - n % 3;
    int col_debut = m - m % 3;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(Grid[i + ligne_debut][j + col_debut] == num){
                return false;
            }
        }
    }
    return true;
}

bool Sudoku::est_valide(int n, int m, int num)
{
    if(est_valide_ligne(n, m, num) && est_valide_col(n, m, num) && est_valide_carre(n, m, num)){
        return true;
    }
    return false;
}

*/