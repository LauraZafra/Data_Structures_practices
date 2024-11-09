
#include <iostream>
#include <cstdlib>
#include <image.h>
using namespace std;

int main(int argc, char *argv[]){
    char *original, *destino; // nombres de los ficheros
    int fila, col, lado;

    // Comprobar validez de la llamada
    if (argc != 6){
        cerr << "Error: Numero incorrecto de parametros.\n";
        cerr << "Uso: szoom <FichImagenOriginal> <FichImagenDestino> nrow ncol lado"
                "\n";
        exit (1);
    }

    // Obtener argumentos
    original  = argv[1];
    destino = argv[2];
    fila = stoi(argv[3]);
    col = stoi(argv[4]);
    lado = stoi(argv[5]);

    // Mostramos argumentos
    cout << endl;
    cout << "Fichero origen: " << original << endl;
    cout << "Fichero resultado: " << destino << endl;

    // Leer la imagen del fichero de entrada
    Image sin_ampliar;
    if (!sin_ampliar.Load(original)){
        cerr << "Error: No pudo leerse la imagen." << endl;
        cerr << "Terminando la ejecucion del programa." << endl;
        return 1;
    }

    // Crear la subimagen
    Image recortada;
    recortada = sin_ampliar.Crop(fila, col, lado, lado);


    // Crear la imagen ampliada de tamaño (2n-1) * (2n-1)
    // para su cálculo tenemos en cuenta solo la subimagen de sin_ampliar
    // con esquina superior izquierda (fila, col) y tamaño lado * lado
    //Image ampliada(2*lado-1, 2*lado-1);

    // Asignar los valores a la imagen ampliada
     sin_ampliar = recortada.Zoom2X();

    // Guardar la imagen ampliada en el fichero resultado
    if (sin_ampliar.Save(destino))
        cout  << "La imagen se guardo en " << destino << endl;
    else{
        cerr << "Error: No pudo guardarse la imagen." << endl;
        cerr << "Terminando la ejecucion del programa." << endl;
        return 1;
    }

}