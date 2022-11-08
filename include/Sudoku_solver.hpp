#pragma once
#include "Sudoku.hpp"
#include <cmath>
#include <cassert>

class Sudoku_solver{
    public:
        Sudoku_solver(){};
        bool est_valide(Sudoku, int, int, int);
        bool solve_backtracking(Sudoku, int, int);
};