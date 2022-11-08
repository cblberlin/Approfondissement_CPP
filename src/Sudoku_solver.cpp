#include "Sudoku_solver.hpp"

bool Sudoku_solver::est_valide(Sudoku s, int x, int y, int val)
{
    int n = s.getSize();
    for(int i = 0; i < n; i++){
        // check pour linge
        if(s(x, i) == val) return false;
        // check pour colonne
        if(s(i, y) == val) return false;
        // check pour le carre
        if(s(3 * (x / 3) + i / 3,  3 * (y / 3) + i % 3 ) == val) return false;
    }
    // si tous est passe alors que ce placement est valide
    return true;
}

bool Sudoku_solver::solve_backtracking(Sudoku S, int ligne, int col)
{
    int n = S.getSize();
    
    // check pour si on est a la fin du grid
    if(ligne == n){
        return false;
    }

    // 
    if(S(ligne, col) != 0){
        //cout << "test: " << ligne << " " << col << endl;
        if(col == n - 1){
            if(solve_backtracking(S, ligne + 1, 0)) return true;
        } else {
            if(solve_backtracking(S, ligne, col + 1)) return true;
        }
        return false;
    }
    //cout << " test 2 " << endl;
    // essaie d'autres valeurs
    for(int val = 1; val <= 9; val++){
        if(est_valide(S, ligne, col, val)){
            S(ligne, col) = val;
            if(ligne == n - 1){
                if(solve_backtracking(S, ligne + 1, 0)) return true;
            } else {
                if(solve_backtracking(S, ligne, col + 1)) return true;
            }
        }
    }

    // si ce n'est pas correct, on backtrack
    S(ligne, col) = 0;
    return false;
}