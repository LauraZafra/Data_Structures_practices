#include <iostream>
#include <fstream>
#include "letters_set.h"
#include <string>
#include <cassert>
using namespace std;

LettersSet readFromFile(const char filename[]){

    ifstream f;
    LettersSet l;

    f.open(filename);
    if(!f)
        cout << "Error abriendo el fichero." << endl;
    else
    {
        f >> l;
        f.close();
    }
    return l;
}

int main(int nargs, char *argv[]){
    //Comprueba si el número de argumentos es 3, si no, saca un mensaje de error.
    if(nargs == 3){
        //Lee un LetterSet desde un archivo
        LettersSet l = readFromFile(argv[1]);
        //Calcula la puntuación a la palabra y la imprime por pantalla
        cout << l.getScore(argv[2]) << endl;
    }
    else cerr << "Número de parámetros incorrecto";
}