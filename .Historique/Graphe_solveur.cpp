#include "Graphe_solveur.hpp"

bool Graphe_solveur::est_valide(int u, int couleur) {
    list<int>::iterator it;
    for(it=adj[u].begin();it!=adj[u].end();++it){
    if(color[*it] == couleur) return false;
    }
    return true;
}

void Graphe_solveur::solve(int sommet) {
    // Initialisation du tableau des voisins.
    voisins = &s_Voisins;
    /* étapes algorithmiques : 
    1) choisir le sommet ayant le moins de possibilités de couleurs (celui qui a le plus de voisins
    en cas d'égalité et choix arbitraire si encore égalité);
    2) Donne la "plus petite couleur" possible à ce sommet, mettre à jour le tableau des couleurs
    disponibles.
    3) Appelle la fonction avec sommet pas encore parcouru (voisin en priorité), utiliser
    "est_valide".
}