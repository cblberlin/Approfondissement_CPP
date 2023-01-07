#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*auto fct1() {
    vector<int> tab (10);
    for(int i = 0; i < 10; i++) {
        tab[i] = 10 - i;
    }
    auto minimum = min(tab.begin(), tab.end());
    auto valeur_1 = find(tab.begin(), tab.end(), minimum);
    return valeur_1;
}*/

int main() {
    vector<int> tab (10);
    for(int i = 0; i < 10; i++) {
        tab[i] = 10 - i;
    }
    auto minimum = min(tab.begin(), tab.end());
    //auto valeur_1 = find(tab.begin(), tab.end(), minimum);
    auto valeur_bis = find_if(tab.begin(), tab.end(), [] (int i) {return i == 10;});
    auto valeur_2 = find_if(tab.begin(), tab.end(), [](int i) {return i == 0;});
    bool res = true;
    cout << res << endl;
    bool resultat = (valeur_bis == tab.begin());
    bool resultat_bis = (valeur_bis == tab.begin()+1);
    bool resultat_ter = (valeur_2 == tab.end());
    cout << resultat << endl;
    cout << resultat_bis << endl;
    cout << resultat_ter << endl;
    //cout << valeur_2 << endl;
    //cout << "Première valeur : " << (int)valeur_1 << endl;
    //cout << "Seconde valeur : " << (int)valeur_2 << endl;
    return 0;
}