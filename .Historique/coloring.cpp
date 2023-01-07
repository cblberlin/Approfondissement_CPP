#include <iostream>
#include<list>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX_COLORS 1001
vector<int> Color(MAX_COLORS,-1);

class Graph{
    protected:
        int V;
        int maxColors;
        list<int> *adj;
    public:
        Graph(int V,int m);
        void addEdge(int u,int v);
        bool coloring(int u);
        bool isSafe(int u,int color);
        void printResult();
};

Graph::Graph(int V,int m){
    this->maxColors = m;
    this->V = V;
    adj = new list<int>[this->V];
}

void Graph::printResult(){
    for(int i=0;i<this->V;i++){
    cout << "Le sommet " << i << " a pour couleur " << Color[i] << endl;
    }
    cout << endl << endl;
}

void Graph::addEdge(int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

bool Graph::isSafe(int u,int color){
    list<int>::iterator it;
    for(it=adj[u].begin();it!=adj[u].end();++it){
    if(Color[*it] == color) return false;
    }
    return true;
}


bool Graph::coloring(int u){
    if(u==this->V) return true;
    for(int i=0;i<this->maxColors;i++){
        if(isSafe(u,i)){
            Color[u] = i; 
            if(coloring(u+1)) return true;
                Color[u] = -1; 
            }
        }
    return false;
}

int main(){
    int V = 5;
    int maxColors = 3;
    Graph g(V,maxColors);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(0,3);
    g.addEdge(1,2);
    g.addEdge(3,4);
    int vertexColored = 0;
    if(g.coloring(vertexColored)){
        cout << "Succès. " << endl << endl;
        g.printResult();
    }
    else{
        cout << "Echec de la coloration de graphe." << endl;
    }
    return 0;
}
    


