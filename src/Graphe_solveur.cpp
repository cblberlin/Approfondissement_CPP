#include "Graphe_solveur.hpp"

Graphe_solveur::Graphe_solveur(Graphe_colore & G_) : G(G_){
    G = G_;
}

bool Graphe_solveur::est_valide(int noeud, int couleur) {
    for(size_t i = 0; i < G.voisins(noeud).size(); i++) {
        if(G.get_color(i) == couleur) {
            return false;
        }
    }
    return true;

}

bool Graphe_solveur::solve_backtracking(){
    // initialisation un tab pour le nombre de voisin pour chaque sommet
    int tmp = 0;
    tmp = G.sommet_meilleur();

    if(tmp == G.get_nb_node()){
        G.sol_trouve();
        return true;
    }
    
    vector<int> tab_couleurs_dispo = G.tab_couleurs_dispo(tmp);
    
    size_t i = 0;
    bool cond = false;

    while( !cond && i < tab_couleurs_dispo.size()){
        G.colorer(tmp, tab_couleurs_dispo[i]);
        i++;
        cond = solve_backtracking();
        if(cond == false){
            G.colorer(tmp, -1);
        }
    }
    if(cond){
        G.sol_trouve();
        return true;
    }

    return false;
}

void Graphe_solveur::afficher_resultat(){
    if(G.get_sol()){
        cout << "Ce problème de coloration a une solution pour le max couleur possible " << G.get_max_color() << endl;
        G.afficher_color();
        return;
    }
    cout << "Ce problème de coloration n'a pas de solution pour le max couleur possible " << G.get_max_color() << endl;
    return;
}


