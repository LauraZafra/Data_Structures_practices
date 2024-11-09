

#include <iostream>
#include <cstdlib>
#include <image.h>
using namespace std;

int main(int argc, char *argv[]){
    char *origen, *recorte; // nombres de los ficheros
    int nrow, ncol, height, width;

    // Comprobar validez de la llamada
    if (argc != 7){
        cerr << "Error: Numero incorrecto de parametros.\n";
        cerr << "Uso: subimagen <FichImagenOriginal> <FichImagenDestino> nrow ncol height width"
                "\n";
        exit (1);
    }

    // Obtener argumentos
    origen  = argv[1];
    recorte = argv[2];
    nrow = stoi(argv[3]);
    ncol = stoi(argv[4]);
    height = stoi(argv[5]);
    width = stoi(argv[6]);

    // Mostramos argumentos
    cout << endl;
    cout << "Fichero origen: " << origen << endl;
    cout << "Fichero resultado: " << recorte << endl;

    // Leer la imagen del fichero de entrada
    Image original;
    if (!original.Load(origen)){
        cerr << "Error: No pudo leerse la imagen." << endl;
        cerr << "Terminando la ejecucion del programa." << endl;
        return 1;
    }

    // Mostrar los parametros de la Imagen
    cout << endl;
    cout << "Dimensiones de " << origen << ":" << endl;
    cout << "   Imagen   = " << original.get_rows()  << " filas x " << original.get_cols() << " columnas " << endl;

    //Crear la imagen recortada y copiar valores de la imagen original
    Image image;
    image = original.Crop(nrow, ncol, height, width);

    // Guardar la imagen resultado en el fichero
    if (image.Save(recorte))
        cout  << "La imagen se guardo en " << recorte << endl;
    else{
        cerr << "Error: No pudo guardarse la imagen." << endl;
        cerr << "Terminando la ejecucion del programa." << endl;
        return 1;
    }

}
