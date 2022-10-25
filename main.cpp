#include <iostream>
#include "Graph.hpp"

using namespace std;

int main(){

    // test pour constructeur 
    int n = 9;
    Graph g(n);
    cout << g.size() << endl;
    return 0;
}