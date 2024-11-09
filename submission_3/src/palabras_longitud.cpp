#include <iostream>
#include "dictionary.h"
#include <fstream>
#include <string>
#include <cerrno>
using namespace std;

Dictionary readFromFile(const char filename[]){

    ifstream f;
    Dictionary d;

    f.open(filename);
    if(!f)
        cout << "Error abriendo el fichero." << endl;
    else
    {
        f >> d;
        f.close();
    }
    return d;
}

int main(int nargs, char *argv[]) {
    //Comprueba si el número de argumentos es 3, si no, saca un mensaje de error.
    if (nargs != 3){
        cerr << "Número de parámetros incorrecto" << endl;
    }
    else{
        //Leemos un Dictionary desde un archivo
        Dictionary d = readFromFile(argv[1]);
        int longitud = stoi(argv[2]);
        //Obtenemos un vector de string con las palabras de la longitud pasada como argumento
        vector <string> palabras = d.wordsOfLength(longitud);
        cout << "Palabras de longitud " << longitud << endl;
        //Imprimimos el vector
        for(int i=0;i<palabras.size();i++){
            cout << palabras[i] << endl;
        }
    }
}