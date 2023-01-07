#pragma once

#include <utility>
#include <map>
#include <iostream>

using namespace std;

class Arete{
    private:
        pair<int, int> arete;
    public:
        // constructeur
        Arete(int, int);    
        // afficher
        void afficher() {cout << "(" << arete.first << ", " << arete.second << ")" << " ";}
        
        
};