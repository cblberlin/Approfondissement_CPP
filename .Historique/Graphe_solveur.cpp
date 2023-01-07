#include "Graphe_solveur.hpp"

bool Graphe_solveur::est_valide(int noeud, int couleur) {
    for(int i = 0; i < get_voisins(noeud).size(); i++) {
        if(G.color[i] == couleur) {
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
    vector<int> resultat_auxiliaire = tableau_nombre_voisins();
    vector<int> resultat [n];
    for(int i; i < n; i++) {
        int compteur = 0;
        m = resultat_auxiliaire[i];
        for(int j; j < m; j++) {
            if(G.color[G.get_s_Voisins[j]] != -1) compteur += 1;
        }
        resultat[i] = max_color - compteur;
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
        if(est_valide(sommet, it)){
            G.colorer(sommet, it);
            if(solve_backtracking(sommet + 1)){
                return true;
    
            else{
                G.colorer(sommet, -1);
            }
            }
        }

    }
    return false;
}

/*    vector<int> vois_bis = vois;

    auto non_colore = [] (int i) {return color[i] == -1;};
    auto valeur = find_if(nbre_couleurs_dispos.begin(), nbre_couleurs_dispos.end(), non_colore);
    if(valeur == nbre_couleurs_dispos.end()) {return true;}
        //bool assertion = false;
        auto compteur = count_if(nbre_couleurs_dispos.begin(), nbre_couleurs_dispos.end(), non_colore);
        int min_couleur = min_element(nbre_couleurs_dispos.begin(), nbre_couleurs_dispos.end(), [] (int i) {return color[i] == -1});
        // On prendra en compte le critère supplémentaire "a le plus de voisins dans le cas ou plusieurs sommet ont cette valeur minimum" dès que possible.
        // En attendant, le sommet sera le plus petit en terme de notation à minimiser le nombre de couleurs disponibles.
        int sommet_cible = distance(nbre_couleurs_dispos.begin(), min_couleur);
        for(int i = 0; i < max_color; i++) {
            if(est_valide(sommet_cible, i)) {
                colorer(sommet_cible,i);
                //assertion = true;
                break;
                //color[sommet_cible] == i;
            }
        }
        if(solve_backtracking() == false) {
            color[sommet_cible] = -1;
        }
       
    return false;
}*/