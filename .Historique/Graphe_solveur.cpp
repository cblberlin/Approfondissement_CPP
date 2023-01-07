#include "Graphe_solveur.hpp"

bool Graphe_solveur::est_valide(int noeud, int couleur) {
    for(int i = 0; i < get_voisins(noeud).size(); i++) {
        if(color[i] == couleur) {
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
    int n = s_Voisins.size();
    int resultat_auxiliaire = tableau_nombre_voisins();
    vector<int> resultat [n];
    for(int i; i < n; i++) {
        int compteur = 0;
        m = resultat_auxiliaire[i];
        for(int j; j < m; j++) {
            if(color[s_Voisins[j]] != -1) compteur += 1;
        }
        resultat[i] = max_color - compteur;
        // On choisit de ne pas écrire un assert vérifiant qu'il y a au moins une couleur disponible.
        // On laisse ce détail pour le backtracking.
    }
    return resultat;
}

bool Graphe_solveur::solve_backtracking(vector<int> & vois, vector<int> & Zahl_Farben) {
    // Farbe veut dire couleur en allemand, on a déjà utilisé les termes en français et en anglais. Zahl veut dire nombre en allemand.
    // C'est simplement pour une question de visibilité.
    // vois correspondra au tableau retourné par tableau_nombre_voisins().
    // Farbe correspondra au tableau retourné par tableau_nombre_couleurs_dispos().
    int min_couleur = min_element(Zahl_Farben.begin(), Zahl_Farben.end(), [] (int i) {return color[i] == -1});
    // On prendra en compte le critère supplémenrtaire "a le plus de voisins dans le cas ou plusieurs sommet ont cette valeur minimum" dès que possible.
    // En attendant, le sommet sera le plus petit en terme de notation à minimiser le nombre de couleurs disponibles.
    int sommet_cible = distance(Zahl_Farben.begin(), min_couleur);
    for(int i = 0; i < max_color; i++) {
        if(est_valide(sommet_cible, i)) {
            color[sommet_cible] == i;
        }
    }
}


