
#include <iostream>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <image.h>
using namespace std;

int main(int argc, char *argv[]){
    char *origen, *destino;// nombre del fichero

    // Comprobar validez de la llamada
    if (argc != 3){
        cerr << "Error: Numero incorrecto de parametros.\n";
        cerr << "Uso: barajar <FichImagenOriginal> <FichImagenDestino>"
                "\n";
        exit (1);
    }

    // Obtener argumentos
    origen  = argv[1];
    destino = argv[2];

    // Mostramos argumentos
    cout << endl;
    cout << "Fichero origen: " << origen << endl;
    cout << "Fichero destino: " << destino << endl;

    // Leer la imagen del fichero de entrada
    Image original;
    if (!original.Load(origen)){
        cerr << "Error: No pudo leerse la imagen." << endl;
        cerr << "Terminando la ejecucion del programa." << endl;
        return 1;
    }

    // Comprobar que los parámetros sean correctos
    assert(original.size()>0);


    // Barajar la imagen
    //for (int i=0; i<250; i++){
        clock_t tini;
        tini = clock();
        original.ShuffleRows2();
        clock_t tfin;
        tfin = clock();
        cout << "Tiempo de ejecución en segundos: " << "\t" << (tfin - tini)/(double)CLOCKS_PER_SEC << endl;
    //}




    // Guardar la imagen resultado en el fichero
    if (original.Save(destino))
        cout  << "La imagen se guardo en " << origen << endl;
    else{
        cerr << "Error: No pudo guardarse la imagen." << endl;
        cerr << "Terminando la ejecucion del programa." << endl;
        return 1;
    }
}