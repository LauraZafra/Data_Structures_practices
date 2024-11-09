/**
 * @file maxqueue.h
 * @brief  Archivo de especificación del TDA MaxQueue
 * @author Laura Zafra Alarcos, Antonio Manuel de Pablos Pancorbo
 */
#include <stack>
#include <iostream>
using namespace std;

class maxqueue{
private:
    struct elemento {
        int value;
        int maximum;

        /**
         * @brief Sobrecarga del operador de salida.
         * @param os Flujo de salida.
         * @param e Elemento a imprimir por pantalla
         * @return Flujo de salida.
         */
        friend ostream &operator<<(ostream &os, const elemento &e) {
            os << e.value << "," << e.maximum;
            return os;
        }
    };

    stack<elemento> principal;

public:

    /**
     @brief Inserta un nuevo elemento en la cola.
     @param valor del elemento que se inserta.
     @post La cola se modifica.
    **/

    void push(int valor);

    /**
     @brief Devuelve el valor del último elemento que se ha insertado en la cola sin extraerlo.
     @pre La cola debe tener al menos un elemento.
     @post La cola no se modifica.
     @return El ultimo elemento de la cola.
    **/
    elemento front()const;

    /**
     @brief Extrae el último elemento que se ha insertado en la cola.
     @pre La cola debe tener al menos un elemento.
     @post La cola se modifica
    **/
    void pop();

    /**
     @brief Comprueba si la cola esta vacia o no.
     @param c Pila de elementos
     @post El objeto no se modifica.
     @return Si la cola esta vacia.
    **/
    bool estavacia(stack<elemento> & c)const;

    /**
     @brief Devuelve el número de elementos que hay en la cola.
     @param c Pila de elementos a la que se le quiere calcular el tamaño.
     @post El objeto no se modifica.
     @return Tamaño de la cola.
    **/

    int tamanio(stack<elemento> & c)const;
};