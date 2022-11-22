#include "Graphe_solveur.hpp"

bool Graphe_solveur::est_valide(int node, int couleur){

    for(int i = 0; i < G.get_voisins(node).size(); i++){
        if(G.get_color(i) == couleur){
            return false;
        }
    }
    return true;
}

bool Graphe_solveur::solve_backtracking(int i){

}