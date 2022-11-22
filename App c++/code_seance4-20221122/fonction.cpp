#include<iostream>

using namespace std;

class Erreur {
};

int f(int a)
    throw (int, Erreur); // signifie que la fonction peut lancer des exceptions de type int et Erreur


int main() {

    try{
        f(2);
    }
    catch(int)
    {
        cout << "Exception de type int" << endl;
    }
    catch(Erreur)
    {
        cout << "Exception de type Erreur" << endl;
    }
    catch(...)
    {
        cout << "Exception d'un autre type" << endl;
    }
    return 1;
}


int f(int a)
    throw (int, Erreur)
{
    if(a == 0)
        throw a;

    if(a == 1)
        throw Erreur();

    if(a == 2)
        throw 1.5;

    return 1;
}
