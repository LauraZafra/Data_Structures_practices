#ifndef __DICTIONARY_H__
#define __DICTIONARY_H__
#include <string>
#include "set"
#include "vector"
#include <iostream>
using namespace std;

/**
 * @brief TDA Dictionary formado por un set de string al que hemos llamado words
 * @details Almacena las palabras de un fichero de texto y permite iterar sobre ellas
 * @param words Set formado por un string, cuyos datos no se repiten y se encuentran ordenados
 * por orden alfabético y longitud de la palabra.
 */

class Dictionary {
private:
    set <string> words;
public:
    /**
     * @brief Constructor por defecto sin parámetros de un Dictionary
     * @post El Dictionary se crea vacío
     */
    Dictionary();

    /**
    * @brief Constructor de copia de un Dictionary
    * @param other Dictionary a copiar
    */
    Dictionary(const Dictionary & other);

    /**
     * @brief Combrueba si una palabra se encuentra en el diccionario
     * @param val Palabra a buscar en el diccionario
     * @return Si la palabra está en el Dictionary o no
     * @post El Dictionary no se modifica
     */
    bool exists(const string & val) const;

    /**
    * @brief  Inserta una nueva palabra en el Dictionary
    * @param val Palabra a insertar en el Dictionary
    * @return Si se ha podido insertar o no. Si ya se encontraba la palabra devolverá false, puesto que solo inserta en caso de que no estuviera
    */
    bool insert(const string & val);

    /**
     * brief Elimina una palabra del diccionario
     * @param val Palabra que se quiere eliminar del Dictionary
     * @return Si la palabra se ha borrado del diccionario o no
     */
    bool erase(const string & val);

    /**
     * brief Limpia el diccionario, borra todas las palabras contenidas en él
     * post Queda un Dictionary vacío
     */
    void clear();

    /**
     * brief Comprueba si el diccionario está vacío
     * @return Si el diccionario está vacío o no
     * @post El Dictionary no se modifica
     */
    bool empty()const;

    /**
     * brief Comprueba el tamaño del diccionario
     * @return unsigned int que indica el número de palabras en el Dictionary
     */
    unsigned int size()const;

    /**
     * brief Comprueba el número de veces que aparece una letra en todo el diccionario
     * @param c Letra que se quiere buscar en el diccionario
     * @return int que indica cuántas veces está c en el Dictionary
     */
    int getOccurences(const char c);

    /**
     * @brief Cuenta el total de letras de un diccionario
     * @return Entero con el total de letras
     */
    int getTotalLetters();

    /**
     * @brief Devuelve las palabras en el diccionario con una longitud dada
     * @param length Longitud de las palabras buscadas
     * @return Vector de palabras con la longitud deseada
     */
    vector<string> wordsOfLength(int length);

    /**
     * @brief Sobrecarga del operador de salida para Dictionary
     * @param os Flujo de salida
     * @param d Dictionary del que se extraen los datos
     * @return Flujo de salida
     */
    friend ostream & operator << (ostream & os, const Dictionary & d);

    /**
     * @brief Sobrecarga del operador de entrada para Dictionary
     * @param is Flujo de entrada
     * @param d Dictionary donde se guarda la información
     * @return Flujo de entrada
     */
    friend istream & operator >> (istream & is, Dictionary & d);
};

#endif
