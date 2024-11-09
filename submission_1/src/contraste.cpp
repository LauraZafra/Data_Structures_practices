
#include <iostream>
#include <cstdlib>
#include <image.h>
using namespace std;

int main(int argc, char *argv[]){
    char *origen, *destino; // nombre de los ficheros
    int in1, in2, out1, out2;

    // Comprobar validez de la llamada
    if (argc != 7){
        cerr << "Error: Numero incorrecto de parametros.\n";
        cerr << "Uso: subimagen <FichImagenOriginal> <FichImagenDestino> nrow ncol height width"
                "\n";
        exit (1);
    }

    // Obtener argumentos
    origen  = argv[1];
    destino = argv[2];
    in1 = stoi(argv[3]);
    in2 = stoi(argv[4]);
    out1 = stoi(argv[5]);
    out2 = stoi(argv[6]);

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


    // Ajustar la imagen
    original.AdjustContrast(in1, in2, out1, out2);

    // Guardar la imagen resultado en el fichero
    if (original.Save(destino))
        cout  << "La imagen se guardo en " << origen << endl;
    else{
        cerr << "Error: No pudo guardarse la imagen." << endl;
        cerr << "Terminando la ejecucion del programa." << endl;
        return 1;
    }
}