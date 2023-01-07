#pragma once

#include <utility>
#include <map>

using namespace std;

class Arrete{
    private:
        pair<int, int> arrete;
    public:
        // constructeur
        Arrete(int debut, int fin){
            pair<int, int> arrete;
            arrete = make_pair(debut, fin);
        }

        // destructeur
        
};