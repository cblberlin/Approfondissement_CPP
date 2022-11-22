#include <iostream>

using namespace std;

// quatre classes representant quatre exceptions differentes
class Erreur {
};

class Erreur1 {
};

class Erreur2 {
};

class Erreur3{
};

// une classe specialisee a partir de l'Erreur1
class Erreur1spe : public Erreur1 {
};

// une fonction qui va lancer des exceptions
void fonction_erreur(int a);

// on appelle l'executable en lui donnant un entier en argument
int main(int argc, char *argv[]) {

    int a = stoi(argv[1]); // stoi : string to integer
    try{
        fonction_erreur(a);
    }
    catch(Erreur1)
    {
        cout << "Erreur de type Erreur1" << endl;
    }
    catch(Erreur2)
    {
        cout << "Erreur de type Erreur2" << endl;
    }
    catch(...)
    {
        cout << "Erreur de type quelconque" << endl;
    }

    return 0;
}


void fonction_erreur(int a) {
    if(a == 1)
        throw Erreur1();
    if(a == 2)
        throw Erreur2();
    if(a == 3)
        throw Erreur3();
    if(a == 11)
        throw Erreur1spe();

    throw Erreur();
}
