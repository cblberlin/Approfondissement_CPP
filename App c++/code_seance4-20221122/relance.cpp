#include <iostream>

using namespace std;

class ErreurAllocLigne {
    // ligne : numero de ligne ou il y a eu un probleme d'allocation memoire
    int ligne;

public:
    ErreurAllocLigne(int l) : ligne(l) {}
};

void allocation_mat(int, int, double**&);
void allocation_ligne(int, double*&, int);
void liberation_mat(int, int, double**&);


// dans ce programme, on alloue de la memoire pour stocker les coefficients d'une matrice
// puis on libere cette memoire
// la memoire est stockee par lignes dans un tableau de lignes (double**)

// on va etudier la gestion d'une erreur d'allocation dans une ligne
// on appelle ErreurAllocLigne l'exception associee a cette erreur

int main()
{
    // taille de la matrice
    int N = 10, M = 5;

    double** pp_mat; // adresse

    // on alloue de la memoire pour une matrice
    allocation_mat(N,M,pp_mat);

    // on libere cette memoire
    liberation_mat(N,M,pp_mat);

    cout << "fin du programme" << endl;
    return 1;
}

// N : nombre de lignes a allouer
// M : nombre de colonnes a allouer
// adresse : adresse dans laquelle stocker les coefficients
void allocation_mat(int N, int M, double** & adresse) {
    adresse = new double*[N];

    // on initialise toutes les lignes
    for(int i=0; i<N; i++)
        allocation_ligne(M, adresse[i], i);
}

// M : taille de la ligne a allouer
// adresse : adresse dans laquelle stocker les coefficients
// num : numero de la ligne courante (utile uniquement pour lancer l'exception)
// la methode initialise les coefficients a zero
void allocation_ligne(int M, double* & adresse, int num) {
    adresse = new double[M];

    // imaginons qu'une erreur se produise lors de l'allocation d'une ligne particuliere :
    if(num == 100)
    {
        // dans ce cas on libere la memoire qui vient d'etre allouee et on renvoie une exception
        delete[] adresse;
        throw ErreurAllocLigne(num);
    }

    // on initialise les coefficients a zero
    for(int i=0; i<M; i++)
        adresse[i] = 0;
}

// libere la memoire associee a une matrice
// N : nombre de lignes
// M : nombre de colonnes
void liberation_mat(int N, int M, double** & adresse) {
    // on commence par liberer les lignes
    for(int i=0; i<N; i++)
        delete[] adresse[i];

    // on libere le tableau de lignes
    delete[] adresse;
}
