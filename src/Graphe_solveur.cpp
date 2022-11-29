#include "Graphe_solveur.hpp"

Graphe_solveur::Graphe_solveur(Graphe_colore G_): G(G_){
}

bool Graphe_solveur::est_valide(int noeud, int couleur) {
    for(int i = 0; i < G.voisins(noeud).size(); i++) {
        if(G.get_color(i) == couleur) {
            return false;
        }
    }
    return true;
    //vector<int>::iterator it;
    //for(it=adj[u].begin();it!=adj[u].end();++it){
    //if(color[*it] == couleur) return false;
    //}
    //return true;
}

vector<int> Graphe_solveur::tableau_nombre_couleurs_dispos() {
    int n = G.get_nb_node();
    vector<int> resultat_auxiliaire = G.tableau_nombre_voisins();
    vector<int> resultat;
    for(int i = 0; i < n; i++) {
        int compteur = 0;
        //int m = resultat_auxiliaire[i];
        for(auto &j: G.voisins(i)) {
            if(G.get_color(j) != -1) compteur += 1;
        }
        resultat.push_back(G.get_max_color() - compteur);
        // On choisit de ne pas écrire un assert vérifiant qu'il y a au moins une couleur disponible.
        // On laisse ce détail pour le backtracking.
    }
    return resultat;
}

bool Graphe_solveur::solve_backtracking(int sommet) { // (int sommet, int couleur) //(vector<int> & vois, vector<int> & nbre_couleurs_dispos) {
    // Farbe veut dire couleur en allemand, on a déjà utilisé les termes en français et en anglais. Zahl veut dire nombre en allemand.
    // C'est simplement pour une question de visibilité.
    // vois correspondra au tableau retourné par tableau_nombre_voisins().
    // Farbe correspondra au tableau retourné par tableau_nombre_couleurs_dispos().
    if(sommet == G.get_nb_node()) return true;

    // initialiser le tableau de couleur possible
    vector<int> tab_couleur_possible = tableau_nombre_couleurs_dispos();
    // trier le tableau comme l'algo demande
    
    vector<int>::iterator it;
    for(it = tab_couleur_possible.begin(); it != tab_couleur_possible.end(); it++){
        if(est_valide(sommet, *it)){
            G.colorer(sommet, *it);
            if(solve_backtracking(sommet + 1)){
                return true;
            }
            G.colorer(sommet, -1);
        }

    }
    return false;
}
