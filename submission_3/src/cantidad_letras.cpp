#include <iostream>
#include "dictionary.h"
#include "letters_set.h"
#include <fstream>
#include <string>
#include <cerrno>
using namespace std;

LettersSet readFromFileLetter(const char filename[]){

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

Dictionary readFromFileDic(const char filename[]){

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
    if (nargs != 3){
        cerr << "Número de parámetros incorrecto" << endl;
    }
    else{
        double ocurrencias, frecuencia;
        char letra;

        //Leemos un Dictionary y un LettersSet desde archivo
        Dictionary d = readFromFileDic(argv[1]);
        LettersSet l = readFromFileLetter(argv[2]);

        //Calculamos el total de letras en el diccionario
        int total = d.getTotalLetters();

        //Recorremos cada letra del LettersSet
        map <char, LetterInfo>::const_iterator pos;
        cout << "Letra\tFAbs.\tFrel." << endl;
        for(pos = l.cbegin(); pos != l.cend(); ++pos){
            //Calculamos el número de veces que aparece cada letra en el diccionario (Frecuencia absoluta)
            ocurrencias = d.getOccurences((*pos).first);
            //Calculamos la frecuencia relativa de cada letra en el diccionario
            frecuencia = ocurrencias/total;
            letra = toupper((*pos).first);
            //Imprimimos el resultado por pantalla
            cout << letra << "\t" << ocurrencias << "\t" << frecuencia << endl;
        }
    }
}