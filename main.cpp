#include <iostream>
#include "Graphe_colore.hpp"
#include "Graphe_solveur.hpp"
#include "Sudoku.hpp"
#include <vector>
#include <string>

using namespace std;

int main(){
    cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
    cout << "%%%%%%%%%%%%%%%%%%%%%%%% La partie coloration du graphe %%%%%%%%%%%%%%%%%%%%%%%%" << endl;
    cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;

    cout << endl << "%%%%%%%%%%%%%%%%%% L'exemple du wikipedia: Graphe de Petersen %%%%%%%%%%%%%%%%%%" << endl << endl;
    Graphe_colore G(10, 3);

    // ajouter les arêtes, ici les arête sont considérés comme non-directionnel
    G.ajout_arete(0, 1);
    G.ajout_arete(0, 2);
    G.ajout_arete(0, 5);
    G.ajout_arete(1, 6);
    G.ajout_arete(1, 7);
    G.ajout_arete(2, 3);
    G.ajout_arete(2, 8);
    G.ajout_arete(3, 4);
    G.ajout_arete(3, 7);
    G.ajout_arete(4, 5);
    G.ajout_arete(4, 6);
    G.ajout_arete(5, 9);
    G.ajout_arete(6, 8);
    G.ajout_arete(7, 9);
    G.ajout_arete(8, 9);

    cout << "le nombre de sommet du Graphe est " << G.get_nb_node() << endl << endl;

    // doit être 15
    cout << "le nombre d'arête du Graphe est " << G.get_nb_edge() << endl << endl;

    // afficher les arête, le nombre total doit être 30 parce que c'est des arête orienté
    G.afficher_arete();
    cout << endl;

    // afficher les liste d'adjacente
    cout << "Le graphe peut se présenter par une liste d'adjacente comme suivant:" << endl;
    G.afficher();

    // afficher les couleurs
    cout << endl << "les sommets sont colorés comme ci-dessous:" << endl;
    G.afficher_color();
    cout << endl;
    // résoud le pb
    G.Init();
    Graphe_solveur G_solve(G);
    //cout << "test" << endl;
    
    
    G_solve.solve_backtracking();
    // 0 1 1 2 0 1 2 0 0 2
    cout << "les sommets sont colorés comme ci-dessous:" << endl;
    G_solve.afficher_resultat();

    cout << endl << "%%%%%%%%%%%%%%%%%%%%%%%%%%% L'exemple du myciel3.col %%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl << endl;
    int i = 2;
    Graphe_colore G2("tests/myciel3.col", i);
    cout << "Le graphe peut se présenter par une liste d'adjacente comme suivant:" << endl;
    G2.afficher();
    cout << endl;
    cout << "les sommets sont colorés comme ci-dessous:" << endl;
    G2.afficher_color();
    cout << endl;
    while(i < G2.get_nb_node()){
        Graphe_colore G2("tests/myciel3.col", i);
        //G2.afficher_arete();
        //G2.afficher_color();
        Graphe_solveur G_solve2(G2);
        G_solve2.solve_backtracking();
        G_solve2.afficher_resultat();
        if(G2.get_sol()){
            break;
        }
        i++;
    }
    cout << endl << endl<< "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
    cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% La partie Sudoku %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
    cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl << endl;

    cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% Le Mini Sudoku %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl << endl;
    vector< vector<int> > grid{ {0, 0, 0, 1}, {3, 0, 4, 0}, {0, 3, 0, 0}, {2, 0, 0, 0} };
    Sudoku S(grid);
    cout << "Le mini Sudoku 4 x 4 est comme suivant:" << endl;
    S.afficher_grid();
    
    cout << endl << "Il peut se présenter par une liste d'adjactente comme suivante:" << endl;
    S.afficher();

    //cout << endl << "Il peut se résoud par le back-tracking" << endl;
    Graphe_solveur G_solve3(S);
    G_solve3.solve_backtracking();
    S.afficher_result();
    
    
    cout << endl << endl << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% Le Sudoku 9 x 9 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl << endl;
    vector< vector<int> > grid2{ {5, 3, 0, 0, 7, 0, 0, 0, 0}, 
                                 {6, 0, 0, 1, 9, 5, 0, 0, 0}, 
                                 {0, 9, 8, 0, 0, 0, 0, 6, 0}, 
                                 {8, 0, 0, 0, 6, 0, 0, 0, 3},
                                 {4, 0, 0, 8, 0, 3, 0, 0, 1},
                                 {7, 0, 0, 0, 2, 0, 0, 0, 6},
                                 {0, 6, 0, 0, 0, 0, 2, 8, 0},
                                 {0, 0, 0, 4, 1, 9, 0, 0, 5},
                                 {0, 0, 0, 0, 8, 0, 0, 7, 9} };
    Sudoku S2(grid2);
    cout << "Le Sudoku 9 x 9 est comme suivant:" << endl;
    S2.afficher_grid();
    Graphe_solveur G_solve4(S2);
    G_solve4.solve_backtracking();
    S2.afficher_result();
    return 0;
}