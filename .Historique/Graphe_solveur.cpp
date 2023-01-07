#include "Graphe_solveur.hpp"

Graphe_solveur::Graphe_solveur(Graphe_colore & G_) : G(G_){
    G = G_;
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

    /*int n = tab_couleur_possible.size();
    for(int i = 0; i < n; i++) {
        if(est_valide(sommet, i)) {
            G.colorer(sommet, i);
            if(solve_backtracking(sommet + 1)) {
                return true;
            }
            G.colorer(sommet,-1);
        }
    }*/
    return false;
}

/*bool Graphe::estValide(){           // Fonction qui r�alise la partie r�cursive de l'algorithme de backtracking

    int meilleur_sommet = mini();   // Sommet ayant le moins de couleurs possibles

    if (meilleur_sommet == -1){     // Si chaque sommet a une couleur, renvoie true
        return true;
    }

    else {
        std::vector<int> tab_coul_dispo = cols(meilleur_sommet);  // Copie du tableau contenant les couleurs disponibles pour meilleur_sommet sachant que la liste est tri�e par ordre croissant

        int i = 0;                         // On donne � ce sommet la plus petite couleur possible, sera incr�ment� si cette couleur n'est pas valide

        bool cond = false;          // Variable qui stocke le bool�en que va renvoyer estValide

        int t = tab_coul_dispo.size();      // Pour �viter un warning du compilateur, comparaison entre un long long int et un int

        while( !cond && i < t ){    // Tant que cond est false et que i < t
            MAJ( meilleur_sommet, tab_coul_dispo[i], true );    // on met � jour le graphe au sommet "meilleur_sommet", avec la couleur "tab_coul_dispo[i]"
            i++;
            cond = estValide();             // appel r�cursif de estValide
            if (cond == false){
                MAJ( meilleur_sommet, tab_coul_dispo[i], false );       // On annule la mise � jour pr�c�dente si cond vaut false
            }
        }
        if (cond){
            return true;    // Renvoie true si cond vaut true
        }

        else {
            return false;   // Renvoie false si cond vaut false
        }
    }

}*/

void Graphe_solveur::print_result() {
    int n = G.get_nb_node();
    for(int i=0; i<n; i++){
    cout << "Le sommet " << i << " a pour couleur " << G.get_color(i) << endl;
    }
    cout << endl << endl;
}
