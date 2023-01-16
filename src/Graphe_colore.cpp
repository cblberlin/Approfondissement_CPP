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
    //color_dispo.resize(nb_node);
    for(int i = 0; i < nb_node; i++){
        color[i] = -1;
    }
    sol = false;
}

Graphe_colore::Graphe_colore(vector<vector<int> > G, int max_color_){
    assert(G.size() == G[0].size());
    int n = G.size();
    nb_node = n;
    max_color = max_color_;
    v_Arete = new vector<Arete>[n];
    s_Voisins = new set<int>[n];
    color = vector<int> (n);
    sol = false;
    for(size_t i = 0; i < G.size(); i++){
        // Initialiser les couleurs comme non-coloré
        color[i] = -1;
        for(size_t j = 0; j < G.size(); j++){
            if(G[i][j] != 0){
                ajout_arete(i, j);
                ajout_arete(j, i);
                s_Voisins[i].insert(j);
                s_Voisins[j].insert(i);
            }
        }
    }
}

Graphe_colore::Graphe_colore(string nom_fichier, int max_color_){
    try{
        ifstream f(nom_fichier);
        if (!f.is_open()){
            throw runtime_error("Erreur: le fichier n'est pas trouvé\n");
        }
        string input;
        f >> input;
        while(input != "edge"){
            f >> input;
        }
        int nb_edge;
        f >> nb_node >> nb_edge;
        max_color = max_color_;
        int i, j;
        char e;
        v_Arete = new vector<Arete>[nb_node];
        s_Voisins = new set<int>[nb_node];
        color = vector<int> (nb_node, -1);
        sol = false;
        while(!f.eof()){
            f >> e >> i >> j;
            ajout_arete(i-1, j-1);
            s_Voisins[i-1].insert(j-1);
        }
        f.close();
    } catch (const exception & e){
        cerr << e.what() << endl;
    }
}

void Graphe_colore::Init(){
    for(int i = 0; i < nb_node; i++){
        color[i] = -1;
    }
}

int Graphe_colore::get_nb_edge() const{
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

int Graphe_colore::nb_voisins(int n) const{
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
    for(int i = 0; i < nb_node; i++){
        set<int>::iterator it = s_Voisins[i].begin();
        cout << "liste d'adjacente du noeud " << i << ": ";
        cout << i << " -> ";
        for(; it!= prev(s_Voisins[i].end()); it++){
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
        cout << endl;
    }
    cout << "le nombre total d'arête directionnel est " << cnt << endl;
}

void Graphe_colore::colorer(int i, int j){
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

vector<int> Graphe_colore::tab_couleurs_dispo(int i) const{
    vector<int> couleur_dispo;
    vector<int> res;

    for(auto it : voisins(i)){
        couleur_dispo.push_back(color[it]);
    }

    sort(couleur_dispo.begin(), couleur_dispo.end());

    couleur_dispo.erase(unique(couleur_dispo.begin(), couleur_dispo.end()), couleur_dispo.end());

    size_t j = 0;

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

int Graphe_colore::get_color(int i) const{
    return color[i];
}

vector<int> Graphe_colore::tab_nb_voisins() const{
    vector<int> res;
    for(int i = 0; i < nb_node; i++){
        res.push_back(nb_voisins(i));
    }
    return res;
}

int Graphe_colore::sommet_meilleur() const{
    int sommet_mini = 0;

    while(color[sommet_mini] != -1 && sommet_mini < nb_node){
        sommet_mini++;
    }

    if(sommet_mini == nb_node){
        return nb_node;
    }

    for(int i = sommet_mini + 1; i < nb_node; i++){
        if(color[i] == -1){
            int tmp1 = tab_couleurs_dispo(sommet_mini).size();
            int tmp2 = tab_couleurs_dispo(i).size();
            if(tmp1 > tmp2){
                sommet_mini = i;
            }else if(tmp1 == tmp2){
                if(nb_voisins(sommet_mini) < nb_voisins(i)){
                    sommet_mini = i;
                }
            }
        }
    }

    return sommet_mini;
}

void Graphe_colore::sol_trouve(){
    sol = true;
}