

#include <iostream>
#include <cstdlib>
#include <image.h>
#include <cmath>
using namespace std;

int main(int argc, char *argv[]){
    char *origen, *icono; // nombres de los ficheros
    int factor;

    // Comprobar validez de la llamada
    if (argc != 4){
        cerr << "Error: Numero incorrecto de parametros.\n";
        cerr << "Uso: subimagen <FichImagenOriginal> <FichImagenDestino> nrow ncol height width"
                "\n";
        exit (1);
    }

    // Obtener argumentos
    origen  = argv[1];
    icono = argv[2];
    factor = stoi(argv[3]);

    // Mostramos argumentos
    cout << endl;
    cout << "Fichero origen: " << origen << endl;
    cout << "Fichero resultado: " << icono << endl;

    // Leer la imagen del fichero de entrada
    Image original;
    if (!original.Load(origen)){
        cerr << "Error: No pudo leerse la imagen." << endl;
        cerr << "Terminando la ejecucion del programa." << endl;
        return 1;
    }

    // Crear la imagen de icono
    Image icon(round(original.get_rows()/factor), round(original.get_cols()/factor));

    // Crear el icono
    icon = original.Subsample(factor);

    // Guardar la imagen resultado en el fichero
    if (icon.Save(icono))
        cout  << "La imagen se guardo en " << icono << endl;
    else{
        cerr << "Error: No pudo guardarse la imagen." << endl;
        cerr << "Terminando la ejecucion del programa." << endl;
        return 1;
    }
}