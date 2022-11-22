#include <iostream>
#include <fstream> // pour ofstream, ifstream, fstream

using namespace std;


void open_file_simple(string name);
void open_file_ex(string name);


// une classe permettant de donner des informations sur l'erreur qui s'est produite
// elle contient un membre contenant le nom du fichier que l'on cherchait a ouvrir
class Exception_ouverture_fichier {
private:
    string name_file;
public:
    Exception_ouverture_fichier(string name) : name_file(name) {}
    string get_name() const {return name_file;}
};

// 1. on peut donner des arguments au main
// les arguments du main permettent de recuperer des entrees en ligne de commande
// maintenant on execute le programme avec
// ./exceptions tests.txt
// bien entendu, on peut changer le nom de l'argument
// argc est un entier contenant le nombre d'arguments donnes
// argv : tableau de chaines de caracteres qui represente les arguments donnes en ligne de commande
// argv[0] est le nom de l'executable
// argv[1] contient le premier argument donne
int main(int argc, char *argv[])
{
    cout << "nom de l'executable : " << argv[0] << endl;
    cout << "1er argument donne :  " << argv[1] << endl;

    // on appelle notre fonction intermediaire open_file
    open_file_simple(argv[1]); // on lui donne argv[1] en argument


    // 2. essayer ./exceptions tests.txt
    // ceci devrait creer un fichier test.txt et ecrire dedans (tout fonctionne)

    // 3. essayer ./exceptions test/test.txt
    // si le dossier tests n'existe pas, alors ceci ne fera rien
    // la seule erreur que l'on obtient est celle que l'on a ecrite nous-meme dans le test
    // de plus, cela met fin a l'ouverture du fichier sans que l'on puisse corriger l'adresse de ce fichier

    // On pourrait modifier la fonction open_file_simple pour permettre a l'utilisateur de rentrer un autre nom de fichier en cas d'erreur
    // cependant il y a plus efficace : les exceptions

    // 4. utilisons maintenant une exception pour mieux gerer ce comportement
    // en cas de mauvais argument, on obtient une erreur d'execution

    // open_file_ex(argv[1]);


    // 5. ecrivons le gestionnaire d'exception pour cette exception
    // cela va permettre de demander a l'utilisateur d'entrer un autre nom de fichier

    // {
    //     try{
    //         open_file_ex(argv[1]);
    //     }
    //     catch(Exception_ouverture_fichier &ex)
    //     {
    //         cout << "erreur d'ouverture du fichier " << ex.get_name() << endl;
    //         cout << "ecrivez un nouvau nom de fichier (tapez enter pour valider)" << endl;
    //         string s;
    //         cin >> s;
    //         cout << "ouverture du nouveau fichier : " << s << endl;
    //         open_file_ex(s); // on appelle la fonction d'ouverture avec le nouveau nom de fichier
    //     }
    // }

    cout << "end prog" << endl;
    return 0;
}

// fonction qui ecrit dans un fichier
void open_file_simple(string name)
{
    // la facon la plus simple d'ouvrir un fichier est la suivante

    // ofstream permet d'ecrire dans un fichier
    // ifstream permet de lire
    // fstream permet de lire et ecrire

    ofstream myfile; // pour ecrire
    myfile.open(name); // si le fichier n'existe pas, ca le cree
                       // si quelque chose est deja ecrit, ca l'efface (on peut modifier ce comportement)
    if( !myfile.is_open() ) // on teste si le fichier n'est pas ouvert
    {
        cout << "!! erreur ouverture du fichier" << endl;
        return;
    }
    myfile << "ecriture dans le fichier" << endl;
    myfile.close(); // fermeture du fichier
}



// meme fonction mais si on n'ouvre pas le fichier,
// alors on renvoie une exception
void open_file_ex(string name)
{
    ofstream myfile; // pour ecrire
    myfile.open(name); // si le fichier n'existe pas, ca le cree
                       // si quelque chose est deja ecrit, ca l'efface (on peut modifier ce comportement)
    if( !myfile.is_open() ) // on teste si le fichier n'est pas ouvert
    {
        throw Exception_ouverture_fichier(name);
    }
    myfile << "ecriture dans le fichier" << endl;
    myfile.close(); // fermeture du fichier
}
