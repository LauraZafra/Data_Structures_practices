/**
 * @file imageop.cpp
 * @brief Fichero con definiciones para el resto de métodos de la clase Image
 */

#include <image.h>
#include <cassert>
#include <cmath>
#include <iostream>
using namespace std;

Image Image::Crop(int nrow, int ncol, int height, int width) const{

    // Comprobar que los parámetros sean correctos
    assert(nrow>=0 && ncol>=0 && width>0 && height>0);
    assert(size()>0);
    assert(nrow+width<=get_cols() && ncol+height<=get_rows());

    // Crear la imagen recortada y copiar valores de la imagen original
    Image recortada(height, width);
    for (int i=nrow; i<height+nrow; i++){
        for (int k=ncol; k<width+ncol; k++){
            recortada.set_pixel(i-nrow, k-ncol, get_pixel(i, k));
        }
    }

    // Devolver la imagen recortada
    return recortada;
}


double Image::Mean (int i, int j, int height, int width) const{
    double suma=0;
    for (int k=i; k<height+i; k++){
        for (int l=j; l<width+j; l++){
            if (k<rows && l<cols) suma += get_pixel(k,l);
        }
    }
    return suma/(height*width);
}


/*Image Image::Subsample(int factor) const{
    assert(factor>0);
    Image icon(ceil(get_rows()/factor), ceil(get_cols()/factor));
    for (int i=0; i<get_rows(); i+=factor){
        for (int j=0; j<get_cols(); j+=factor){
            int media = round(Mean(i,j,factor,factor));
            icon.set_pixel(round(i/factor),round(j/factor),media);
        }
    }
    return icon;
}*/

Image Image::Subsample(int factor) const{ //TEST INCORRECTO
    assert(factor>0);
    Image ultima;
    if (factor == 1) ultima = *this;
    else {
        int lado;
        if (factor >= cols){
            lado = 1;
            Image icon(lado, lado);
            int media = round(Mean(0,0,cols,cols));
            icon.set_pixel(0,0,media);
            ultima = icon;
        }

        else {
            lado = (int)(get_cols()/factor);
            Image icon(lado, lado);
            for (int i=0; i<lado; i++){
                for (int j=0; j<lado; j++){
                    int media = round(Mean(i*factor,j*factor,factor,factor));
                    icon.set_pixel(i,j,media);
                }
            }
            ultima = icon;
        }
    }
    return ultima;
}


/*Image Image::Subsample(int factor) const{
    assert(factor>0);
    Image ultima;
    if (factor == 1) ultima = *this;
    else {
        int lado;
        if (factor >= cols) lado = 1;
        else {
            lado = (int)(get_cols()/factor); //11
        }
        Image icon(lado, lado);
        for (int i=0; i<lado; i++){
            for (int j=0; j<lado; j++){
                int media = round(Mean(i*factor,j*factor,factor,factor));
                icon.set_pixel(i,j,media);
            }
        }
        ultima = icon;
    }
    return ultima;
}*/



Image Image::Zoom2X () const{
    Image ampliada(2*get_rows()-1, 2*get_cols()-1);
    double valor;
    for(int i=0; i<2*get_rows()-1; i++){
        for(int j=0; j<2*get_cols()-1; j++){
            if (i%2==0 && j%2==0) valor = get_pixel(i/2, j/2);
            else if (i%2!=0 && j%2==0) valor = Mean(i/2,j/2,2,1);
            else if (i%2==0 && j%2!=0) valor = Mean(i/2,j/2,1,2);
            else valor = Mean(i/2,j/2,2,2);
            valor = round(valor);
            ampliada.set_pixel(i, j, valor);
        }
    }
    return ampliada;
}


void Image::AdjustContrast(byte in1, byte in2, byte out1, byte out2) {
    double a = (double) in1, b = (double) in2, min = (double) out1, max = (double) out2, formula;
    assert (a>=0 && b>=0 && min>=0 && max>=0 && a<=255 && b<=255 && min<=255 && max<=255);
    double tramo1 = ((min) / (a));
    double tramo2 = ((max-min) / (b-a));
    double tramo3 = ((255-max) / (255-b));

    for (int i=0; i<get_rows()*get_cols(); i++){
        double valor = (double)get_pixel(i);
        if (valor>=0.0 && valor<a) formula = (tramo1 * valor);
        else if (valor>=a && valor<=b) formula = (min + (tramo2 * (valor - a)));
        else if (valor>b && valor<=255.0) formula = (max + (tramo3 * (valor - b)));
        set_pixel(i,(byte)round(formula));
    }
}


void Image::ShuffleRows() {

    const int p = 9973; //O(1)
    Image temp(rows,cols); //O(rows*cols)
    int newr; //O(1)
    // Por la regla del producto, la eficiencia de este bucle es
    // O(rows) * O(cols), es decir O(rows*cols)
    for (int r=0; r<rows; r++){ //O(rows)
        newr = r*p % rows; //O(1)
        for (int c=0; c<cols;c++) //O(cols)
            temp.set_pixel(r,c,get_pixel(newr,c)); //O(1)
    }
    Copy(temp); //O(rows*cols)
    // Por la regla de la suma, la eficiencia de esta función es máx{O(1), O(rows*cols)},
    // es decir, O(rows*cols)

}


void Image::ShuffleRows2() { //O(rows)
    const int p = 9973; //O(1)

    // Crear la imagen sobre la que se barajan las filas
    byte ** temp = new byte * [rows]; //O(1)
    int newr; //O(1)

    for (int k=0; k<rows; k++) { //O(rows)
        // Calcular la fila donde se va a reubicar
        newr = k * p % rows; //O(1)
        temp[k]=img[newr]; //O(1)
    }
    //Destroy();
    delete[]img; //O(1)
    img = temp; //O(1)
}






