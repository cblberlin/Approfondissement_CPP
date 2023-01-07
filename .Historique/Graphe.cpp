#include "Graphe.hpp"

Graphe::~Graphe(){
    delete [] v_Arrete;
    delete [] s_Voisins;
}

Graphe::Graphe(int _nb_node, int _max_color) : nb_node(_nb_node), max_color(_max_color){
    v_Arrete = new vector<Arrete>[nb_node];
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
    v_Arrete = new vector<Arrete>[n];
    s_Voisins = new set<int>[n];
    color = vector<int> (n);
    // créer les conteneurs
    // cout << "test" << endl;
    //cout << G.size() << endl;
    for(int i = 0; i < G.size(); i++){
        // Initialiser les couleurs comme non-coloré
        color[i] = -1;
        //cout << color[i] << endl;
        for(int j = 0; j < G.size(); j++){
            //cout << "test" << endl;
            if(G[i][j] != 0){
                ajout_arrete(i, j);
                ajout_arrete(j, i);
                s_Voisins[i].insert(j);
                s_Voisins[j].insert(i);
            }
        }
    }
}

Graphe::Graphe(string nom_fichier){
    //string fichier_dir = "tests/";

    ifstream f(nom_fichier);
    //if(f.fail()) throw ("0");
    string input;
    f >> input;
    while(input != "edge"){
        f >> input;
        //cout << input << endl;
    }
    int nb_edge;
    f >> nb_node >> nb_edge;
    max_color = nb_node;
    int i, j;
    char e;
    v_Arrete = new vector<Arrete>[nb_node];
    s_Voisins = new set<int>[nb_node];
    color = vector<int> (nb_node);
    while(!f.eof()){
        f >> e >> i >> j;
        //cout << i << " " << j << endl;
        ajout_arrete(i-1, j-1);
        //ajout_arret(j-1, i-1);
        s_Voisins[i-1].insert(j-1);
        //s_Voisins[j-1].insert(i-1);
    }
    f.close();
}

int Graphe::get_nb_edge(){
    int cnt = 0;
    for(int i = 0; i < nb_node; i++){
        cnt += v_Arrete[i].size();
    }
    return cnt/2;
}

void Graphe::ajout_arrete(int n1, int n2){
    v_Arrete[n1].push_back(Arrete(n1, n2));
    v_Arrete[n2].push_back(Arrete(n2, n1));
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
    cout << "Le graphe a " << nb_node << " noeuds " << "et " << get_nb_edge() << " arrêtes" << endl;
    cout << "Le graphe représenté en liste d'adjacente est:" << endl << endl;
    for(int i = 0; i < nb_node; i++){
        set<int>::iterator it = s_Voisins[i].begin();
        cout << "liste d'adjacente du noeud " << i << ": ";
        cout << i << " -> ";
        for(it; it!= prev(s_Voisins[i].end()); it++){
            cout << *it << " -> ";
        }
        cout << *(it++) << endl;
    }
}

void Graphe::afficher_arrete(){
    
}

void Graphe::colorer(int i, int j){
    assert(0 < j < max_color && 0 < i < nb_node);
    color[i] = j;
}