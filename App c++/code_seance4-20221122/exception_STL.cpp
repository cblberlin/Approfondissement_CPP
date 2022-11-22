#include <iostream>


using namespace std;

void test();

int main()
{
    try{
        test();
    }
    catch(runtime_error e) {
        cout << "Exception de type runtime" << endl;
        cout << "Pour plus de precisions : " << e.what() << endl;
    }
    catch(logic_error e) {
        cout << "Exception de type logique" << endl;
        cout << "Pour plus de precisions : " << e.what() << endl;
    }
    catch(exception e) {
        cout << "Exception d'un autre type standard" << endl;
        cout << "Pour plus de precisions : " << e.what() << endl;
    }
    catch(...) {
        cout << "Exception d'un type inconnu" << endl;
    }
    return 1;
}

void test() {
    // domain_error : a utiliser lorsqu'on sort du domaine de definition d'une fonction
    // throw domain_error("Le domaine de definition n'est pas bon ... ");

    // invalid_argument :
    // renvoyer cette exception lorsqu'une valeur donnee en argument n'est pas acceptable
    // cette classe est utilisee dans std::bitset::bitset, dans std::stoi et dans std::stof
    // throw invalid_argument("L'argument donne n'est pas bon ...");

    // length_error : utiliser cette classe quand on depasse la taille limite pour un objet
    // throw length_error("erreur de longueur");

    // out_of_range : utiliser cette classe quand on essaie d'acceder a un element qui est
    // en dehors des indices definis
    // cette classe est utilisee dans std::bitset, std::bit_string, std::stoi, std::stod,
    // std::vector::at, std::map::at, etc...
    // throw out_of_range("on depasse la taille limite");

    // range_error : utile quand un resultat de calcul ne peut pas etre represente
    // par le type dans lequel on voudrait le stocker
    // throw range_error("mauvaise range");

    // overflow_error : represente des erreurs d'overflow
    // (resultat de calcul trop grand pour le type dans lequel on voudrait le stocker)
    // throw overflow_error("overflow");

    // underflow_error : erreurs d'underflow (erreurs liees aux virgules flottantes)
    throw underflow_error("underflow");
}
