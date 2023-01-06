#pragma once

#include <utility>
#include <map>

using namespace std;

class Arret{
    private:
        pair<int, int> arret;
    public:
        // constructeur
        Arret(int debut, int fin){
            pair<int, int> arret;
            arret = make_pair(debut, fin);
        }

        // destructeur
        
};