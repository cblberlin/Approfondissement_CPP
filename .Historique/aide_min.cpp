#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> tab (10,0);
    //<vector>::iterator it;
    auto min_bizarre = min_element(tab.begin(), tab.end(), [](int i){return i != 0;});
    cout << "Valeur du minimum bizarre : " << min_bizarre - tab.begin() << endl;
    //cout << "Indice du minimum bizarre : " << distance(tab.begin(), min_bizarre)
    return 0;
}