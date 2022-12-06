#include "Arete.hpp"
#include "Graphe_colore.hpp"
#include "Graphe_solveur.hpp"
#include <iostream>

int main(){

    // test pour le class Arete.hpp
    Arete A(1,2);

    // doit afficher (1, 2);
    A.afficher();

    // On teste pour le graphe sur wikipedia

    /*

    */

    // test pour le constructeur
    Graphe_colore G(10, 10);

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

    // doit être 10
    cout << "le nombre de sommet du Graphe est " << G.get_nb_node() << endl;

    // doit être 15
    cout << "le nombre d'arête du Graphe est " << G.get_nb_edge() << endl;

    // afficher les arête, le nombre total doit être 30 parce que c'est des arête orienté
    G.afficher_arete();

    // afficher les liste d'adjacente
    G.afficher();

    // test colorer
    cout << "les sommets sont colorés comme ci-dessous:" << endl;
    G.afficher_color();

    G.colorer(0, 1);
    cout << "après la coloration, le tableau devient:" << endl;
    G.afficher_color();

    // test nb_voisins() doit être 3 ... 3 parce que un graphe Petersen est un graphe dont tous les sommets ont 3 voisins
    cout << "test pour nb_voisin()" << endl;
    for(int i = 0; i < G.get_nb_node(); i++){
        cout << G.nb_voisins(i) << " ";
    }
    cout << endl;

    // test voisins()

    cout << "test pour voisins()" << endl;
    
    for(int i = 0; i < G.get_nb_node(); i++){
        cout << "voisins(" << i << ") = (";
        for(auto & j: G.voisins(i)){
            cout << j << " ";
        }
        cout << ")" << endl;
    }

    cout << "test pour le tableau de nombre voisins()" << endl;
    vector<int> tab_nb_voisins = G.tab_nb_voisins();
    for(int i = 0; i < tab_nb_voisins.size(); i++){
        cout << tab_nb_voisins[i] << " ";
    }
    cout << endl;

    cout << "test pour le tableau de couleur possible" << endl;
    for(int i = 0; i < G.get_nb_node(); i++){
        cout << "les couleurs possibles pour sommet " << i << ":";
        vector<int> tab_tmp = G.tab_couleurs_dispo(i);
        for(int j = 0; j < tab_tmp.size(); j++){
            cout << tab_tmp[j] << " ";
        }
        cout << endl;
    }


    Graphe_solveur G_solve(G);
    //G_solve.solve_backtracking(0);
    //G.afficher_color();

    return 0;
}