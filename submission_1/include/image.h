/*!
 * @file image.h
 * @brief Cabecera para la clase Image
 */

#ifndef _IMAGEN_H_
#define _IMAGEN_H_


#include <cstdlib>
#include "imageIO.h"



typedef unsigned char byte;

enum LoadResult: unsigned char {
    SUCCESS,
    NOT_PGM,
    READING_ERROR
};


/**
  @brief T.D.A. Imagen

  Una instancia del tipo de dato abstracto Imagen nos permite almacenar imágenes de intensidades.

  El TDA Imagen proporciona además distintas herramientas para la manipulación de dichas imágenes.

  Para poder usar el TDA Imagen se debe incluir el fichero

  \#include <Imagen.h>

  @author Javier Abad
  @author Guillermo Gómez
  @date Septiembre 2021

**/

class Image{

    /**
         @page page_repImagen Representación del TDA Imagen

         @section sec_Image_A Título A


         Contenido de la sección A.

         @section sec_Image_B Título  B

         Contenido de la sección B.

         Referencia a la \ref sec_Image_A
       **/
private :

    /**
      @brief Puntero a la imagen almacenada

      img apunta a un array-2D dinámico de bytes que contiene la imagen en sí. Almacena tantos bytes como pixeles tenga la imagen.

    **/
    byte **img;

    /**
      @brief Número de filas de la imagen.
    **/
    int rows;


    /**
      @brief Número de columnas de la imagen.
    **/
    int cols;


    /**
      @brief Initialize una imagen.
      @param nrows Número de filas que tendrá la imagen. Por defecto, 0
      @param ncols Número de colunnas que tendrá la imagen. Por defecto, 0
      @param buffer Puntero a un buffer de datos con los que rellenar los píxeles de la imagen. Por defecto, 0.
      @pre filas >= O y columnas >= O
      @post Reserva memoria para almacenar la imagen y la prepara para usarse.
    **/
    void Initialize (int nrows= 0, int ncols= 0, byte *buffer= 0);

    /**
      @brief Lee una imagen PGM desde un archivo.
      @param file_path Ruta del archivo a leer
      @return LoadResult
    **/
    LoadResult LoadFromPGM(const char * file_path);

    /**
      @brief Copy una imagen .
      @param orig Referencia a la imagen original que vamos a copiar
      @pre Asume que no hay memoria reservada o se ha llamado antes a Destroy()
      @pre Asume this != &orig
    **/
    void Copy(const Image &orig);

    /**
      @brief Reserva o copia en memoria una imagen.
      @param nrows Número de filas que tendrá la imagen.
      @param ncols Número de colwnnas que tendrá la imagen.
      @param buffer Puntero a un buffer de datos con los que rellenar los píxeles de la imagen. Por defecto, 0.
      @pre nrows >= O y ncols >= O
      @post Reserva memoria para almacenar la imagen y la prepara para usarse.
    **/
    void Allocate(int nrows, int ncols, byte * buffer = 0);

    /**
      * @brief Destroy una imagen
      *
      * Libera la memoria reservada en la que se almacenaba la imagen que llama a la función.
      * Si la imagen estaba vacía no hace nada .
      */
    void Destroy();

public :

    /**
      * @brief Constructor por defecto .
      * @post Genera una instancia de la clase Imagen con O filas y O colunmas.
      * @return Imagen, el objeto imagen creado.
      */
    Image();

    /**
      * @brief Constructor con parámetros.
      * @param nrows Número de filas de la imagen.
      * @param ncols Número de columnas de la imagen.
      * @param value defecto Valor con el que inicializar los píxeles de la imagen . Por defecto O.
      * @pre n fils > O Y n_cols > O
      * @post La imagen creada es de n_fils y n_cols columnas. Estará inicializada al valor por defecto.
      * @return Imagen, el objeto imagen creado.
      */
    Image(int nrows, int ncols, byte value=0);

    /**
      * @brief Constructor de copias.
      * @param orig Referencia a la imagen original que se quiere copiar.
      * @return Imagen, el objeto imagen creado.
      */
    Image (const Image & orig);

    /**
      * @brief Oper ador de tipo destructor.
      * @return void
      * @post El objeto Imagen destruido no puede usarse salvo que se haga sobre él una operacion Imagen().
      */
    ~Image() ;

    /**
      * @brief Operador de asignación .
      * @param orig Referencia a la imagen original que desea copiarse.
      * @return Una referencia al objeto imagen modificado.
      * @post Destroy cualquier información que contuviera previamente la imagen que llama al operador de asignación.
      */
    Image & operator= (const Image & orig);

    /**
      * @brief Funcion para conocer si una imagen está vacía.
      * @return Si la imagen está vacía
      * @post la imagen no se modifica.
      */
    bool Empty() const;

    /**
      * @brief Filas de la imagen .
      * @return El número de filas de la i magen.
      * @post la imagen no se modifica.
      */
    int get_rows() const;

    /**
      * @brief Columnas de la imagen.
      * @return El número de columnas de la imagen.
      * @post la imagen no se modifica.
      */
    int get_cols() const;

    /**
      * @brief Devuelve el número de píxeles de la imagen.
      * @return número de píxeles de la imagen.
      * @post la imagen no se modifica.
      */
    int size() const;

/**
  * @brief Asigna el valor valor al píxel (@p i, @p j) de la imagen.
  * @param i Fila de la imagen en la que se encuentra el píxel a escribir .
  * @param j Columna de la imagen en la que se encuentra el píxel a escribir.
  * @param value Valor que se escribirá en el píxel (@p i, @p j) .
  * @pre O <= @p i < get_rows()
  * @pre O <= @p j < get_cols()
  * @pre O <= @p value <= 255
  * @post El píxel (@p i, @p j) de la imagen se modificará y contendrá valor @p value.
  * Los demás píxeles permanecerán iguales.
  */
void set_pixel (int i, int j, byte value);

    /**
      * @brief Consulta el valor del píxel (fil, col) de la imagen.
      * @param i Fila de la imagen en la que se encuentra el píxel a consultar.
      * @param j Columna de la imagen en la que se encuentra el píxel a consultar.
      * @pre O <= fil < I.Num_ Filas() II O <= col < I.Num Columnas()
      * @return el valor del píxel contenido en (fil,col)
      * @post La imagen no se modifica.
      */
    byte get_pixel (int i, int j) const;

    /**
      * @brief Consulta el valor del píxel k de la imagen desenrrollada.
      * @param k Índice del píxel
      * @pre 0 <= k < filas*columnas
      * @return el valor del píxel contenido en (k/filas,k%filas)
      * @post La imagen no se modifica.
      */
    byte get_pixel (int k) const;

    /**
      * @brief Asigna el valor valor al píxel k de la imagen desenrollada.
      * @param k Índice del píxel a escribir .
      * @param value Valor que se escribirá en el píxel k.
      * @pre 0 <= k < filas*columnas && O <= valor <= 255
      * @post El píxel k se modificará con el valor de value.
      */
    void set_pixel (int k, byte value);

    /**
      * @brief Almacena imágenes en disco.
      * @param file_path Ruta donde se almacenará la imagen.
      * @pre file path debe ser una ruta válida donde almacenar el fichero de salida.
      * @return Devuelve true si la imagen se almacenó con éxito y false en caso contrario.
      * @post La imagen no se modifica.
      */
    bool Save (const char * file_path) const;

    /**
      * @brief Carga en memoria una imagen de disco .
      * @param file_path Ruta donde se encuentra el archivo desde el que cargar la imagen.
      * @pre @p file_path debe ser una ruta válida que contenga un fichero . pgm
      * @return Devuelve @b true si la imagen se carga con éxito y @b false en caso contrario.
      * @post La imagen previamente almacenada en el objeto que llama a la función se destruye.
      */
    bool Load (const char * file_path);

    /**
      * @brief Obtiene el negativo de una imagen.
      * @return Una referencia al objeto imagen modificado (colores invertidos).
      * @post El objeto que llama a la función se modifica.
      */
    void Invert();

    /**
      * @brief Modifica el contraste de una imagen.
      * @param in1 Umbral inferior de la imagen de entrada.
      * @param in2 Umbral superior de la imagen de entrada.
      * @param out1 Umbral inferior de la imagen de salida.
      * @param out2 Umbral superior de la imagen de salida.
      * @pre 0 <= (in1, in2, out1, out2) <=255 && in1<in2 && out1<out2.
      * @post El objeto que llama a la función se modifica.
      */
    void AdjustContrast (byte in1, byte in2, byte out1, byte out2);

    /**
      * @brief  Calcula la media de los píxeles de una imagen entera o de un fragmento de ésta.
      * @param i Fila donde se empieza a calcular la media.
      * @param j Columna donde se empieza a calcular la media.
      * @param height Altura de la submatriz a la que se calcula la media.
      * @param width Ancho de la submatriz a la que se calcula la media.
      * @pre 0 <= i &&  0 <= j.
      * @return Devuelve la media de los píxeles de la submatriz.
      * @post El objeto que llama a la función no se modifica.
      */
    double Mean (int i, int j, int height, int width) const;


    /**
      * @brief  Genera un icono como reducción de una imagen.
      * @param factor Factor de reducción de la imagen original con respecto al icono.
      * @pre factor > 0.
      * @return Imagen iconizada.
      * @post El objeto que llama a la función no se modifica. La imagen resultante tendrá
      * tamaño int(filas/factor) * int(columnas/factor), descartando los decimales de la división
      */
    Image Subsample(int factor) const;

    /**
      * @brief  Genera una subimagen.
      * @param nrow Fila inicial para recortar.
      * @param ncol Columna inicial para recortar.
      * @param height Número de filas.
      * @param width Número de columnas.
      * @return Devuelve la imagen con el recorte.
      * @post El objeto que llama a la función no se modifica.
      */
    Image Crop(int nrow, int ncol, int height, int width) const;

    /**
      * @brief  Genera una imagen aumentada 2x.
      * @return Devuelve la imagen aumentada.
      * @post El objeto que llama a la función no se modifica. La imagen resultante tendrá
      * tamaño 2n-1*2n-1.
      */
    Image Zoom2X() const;


    /**
      * @brief  Baraja pseudoaleatoriamente las filas de una imagen.
      * @return Devuelve la imagen barajada.
      * @post El objeto que llama a la función se modifica.
      */
    void ShuffleRows();

    void ShuffleRows2();
} ;


#endif // _IMAGEN_H_

