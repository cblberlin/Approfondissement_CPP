#include "Graphe_colore.hpp"

Graphe_colore::~Graphe_colore(){
    delete [] v_Arete;
    delete [] s_Voisins;
}

Graphe_colore::Graphe_colore(int _nb_node, int _max_color) : nb_node(_nb_node), max_color(_max_color){
    v_Arete = new vector<Arete>[nb_node];
    s_Voisins = new set<int>[nb_node];

    // Initialiser tous les noeud comme non-coloré
    color.resize(nb_node);
    for(int i = 0; i < nb_node; i++){
        color[i] = -1;
    }
}

Graphe_colore::Graphe_colore(vector<vector<int> > G){
    assert(G.size() == G[0].size());
    int n = G.size();
    nb_node = n;
    max_color = n;
    v_Arete = new vector<Arete>[n];
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
                ajout_arete(i, j);
                ajout_arete(j, i);
                s_Voisins[i].insert(j);
                s_Voisins[j].insert(i);
            }
        }
    }
}

Graphe_colore::Graphe_colore(string nom_fichier){
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
    v_Arete = new vector<Arete>[nb_node];
    s_Voisins = new set<int>[nb_node];
    color = vector<int> (nb_node);
    while(!f.eof()){
        f >> e >> i >> j;
        //cout << i << " " << j << endl;
        ajout_arete(i-1, j-1);
        //ajout_Arete(j-1, i-1);
        s_Voisins[i-1].insert(j-1);
        //s_Voisins[j-1].insert(i-1);
    }
    f.close();
}

const int Graphe_colore::get_nb_edge(){
    int cnt = 0;
    for(int i = 0; i < nb_node; i++){
        cnt += v_Arete[i].size();
    }
    return cnt/2;
}

void Graphe_colore::ajout_arete(int n1, int n2){
    v_Arete[n1].push_back(Arete(n1, n2));
    v_Arete[n2].push_back(Arete(n2, n1));
    s_Voisins[n1].insert(n2);
    s_Voisins[n2].insert(n1);
}

const int Graphe_colore::nb_voisins(int n){
    //cout << n << ":" << s_Voisins[n].size() << endl;
    assert(n < nb_node);
    return s_Voisins[n].size();
}

set<int> Graphe_colore::voisins(int n) const{
    assert(n < nb_node);
    return s_Voisins[n];
}

set<int>* Graphe_colore::vec_voisins() const{
    return s_Voisins;
}

void Graphe_colore::afficher(){
    //cout << "Le graphe a " << nb_node << " noeuds " << "et " << get_nb_edge() << " arrets" << endl;
    //cout << "Le graphe représenté en liste d'adjacente est:" << endl << endl;
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

void Graphe_colore::afficher_arete(){
    int cnt = 0;
    for(int i = 0; i < nb_node; i++){
        vector<Arete>::iterator it;
        for(it = v_Arete[i].begin(); it != v_Arete[i].end(); it++){
            it->afficher();
            cnt++;
        }
    }
    cout << "le nombre total d'arête est " << cnt << endl;
}

void Graphe_colore::colorer(int i, int j){
    assert(-1 <= j && j < max_color && 0 <= i && i < nb_node);
    color[i] = j;
}

void Graphe_colore::afficher_color(){
    vector<int>::iterator it;
    cout << "la coloration est: [";
    for(it = color.begin(); it != color.end()-1; it++){
        cout << *it << ","; 
    }
    cout << *it << "]" << endl;
}

void Graphe_colore::afficher_nb_voisins(){
    for(int i = 0; i < nb_node; i++){
        cout << nb_voisins(i) << " ";
    }
}

const vector<int> Graphe_colore::tab_couleurs_dispo(int i){
    vector<int> couleur_dispo;
    vector<int> res;

    for(auto it : voisins(i)){
        //cout << "test" << endl;
        //cout << color[*it] << " ";
        couleur_dispo.push_back(color[it]);
    }

    sort(couleur_dispo.begin(), couleur_dispo.end());

    couleur_dispo.erase(unique(couleur_dispo.begin(), couleur_dispo.end()), couleur_dispo.end());\

    int j = -1;

    if(couleur_dispo[j] == -1){j++;}

    for(int k = 0; k < max_color; k++){
        if(k == couleur_dispo[j] && j < couleur_dispo.size()){
            j++;
        }
        else{
            res.push_back(k);
        }
    }

    return res;
}

const int Graphe_colore::get_color(int i){
    return color[i];
}

const vector<int> Graphe_colore::tab_nb_voisins(){
    vector<int> res;
    for(int i = 0; i < nb_node; i++){
        res.push_back(nb_voisins(i));
    }
    return res;
}