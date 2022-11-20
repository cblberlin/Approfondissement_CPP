#include "Graph.hpp"

Graphe::~Graphe(){
    delete [] v_Arret;
    delete [] s_Voisins;
}

Graphe::Graphe(int _nb_node, int _max_color) : nb_node(_nb_node), max_color(_max_color){
    v_Arret = new vector<Arret>[nb_node];
    s_Voisins = new set<int>[nb_node];

    // Initialiser tous les noeud comme non-coloré
    color.resize(nb_node);
    for(int i = 0; i < nb_node; i++){
        color[i] = -1;
    }
}

Graphe::Graphe(vector<vector<int> > G){
    assert(G.size() == G[0].size());
    int n = G.size();
    nb_node = n;
    max_color = n;
    v_Arret = new vector<Arret>[n];
    s_Voisins = new set<int>[n];
    // créer les conteneurs
    for(int i = 0; i < G.size(); i++){
        // Initialiser les couleurs comme non-coloré
        color[i] = -1;
        for(int j = 0; j < G.size(); j++){
            if(G[i][j] != 0){
                ajout_arret(i, j);
                ajout_arret(j, i);
                s_Voisins[i].insert(j);
                s_Voisins[j].insert(i);
            }
        }
    }
}

void Graphe::ajout_arret(int n1, int n2){
    v_Arret[n1].push_back(Arret(n1, n2));
    v_Arret[n2].push_back(Arret(n2, n1));
    s_Voisins[n1].insert(n2);
    s_Voisins[n2].insert(n1);
}

int Graphe::nb_voisins(int n){
    return s_Voisins[n].size();
}

set<int> Graphe::voisins(int n){
    return s_Voisins[n];
}

void Graphe::afficher(){
    for(int i = 0; i < nb_node; i++){
        set<int>::iterator it;
        cout << i << ": ";
        for(it = s_Voisins[i].begin(); it!= s_Voisins[i].end(); it++){
            cout << *it << " ";
        }
        cout << endl;
    }
}