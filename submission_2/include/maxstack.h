/**
 * @file maxstack.h
 * @brief  Archivo de especificación del TDA MaxStack
 * @author Laura Zafra Alarcos, Antonio Manuel de Pablos Pancorbo
 */
#include <queue>
#include <iostream>
using namespace std;

class maxstack{
private:
    struct elemento{
        int value;
        int maximum;

        /**
         * @brief Sobrecarga del operador de salida.
         * @param os Flujo de salida.
         * @param e Elemento a imprimir por pantalla
         * @return Flujo de salida.
         */
        friend ostream & operator<<(ostream &os,const elemento & e) {
            os << e.value << "," << e.maximum;
            return os;
        }
    };
    queue<elemento> principal;


public:

    /**
     @brief Inserta un nuevo elemento en la pila.
     @param valor del elemento que se inserta.
     @post La pila se modifica.
    **/
    void push(int valor);

    /**
     @brief Devuelve el valor del último elemento que se ha insertado en la pila sin extraerlo.
     @pre La pila debe tener al menos un elemento.
     @post La pila no se modifica.
     @return El ultimo elemento de la pila.
    **/
    elemento top()const;

    /**
     @brief Extrae el último elemento que se ha insertado en la pila.
     @pre La pila debe tener al menos un elemento.
     @post La pila se modifica
    **/
    void pop();

    /**
     @brief Comprueba si la pila esta vacia o no.
     @param c Cola de elementos.
     @post El objeto no se modifica.
     @return Si la pila esta vacia.
    **/
    bool estavacia(queue<elemento> & c)const;

    /**
     @brief Devuelve el número de elementos que hay en la pila.
     @param c Cola de elementos a la que se le quiere calcular el tamaño.
     @post El objeto no se modifica.
     @return Tamaño de la pila.
    **/
    int tamanio(queue<elemento> & c)const;
};