/**
 * @file maxqueue.cpp
 * @brief  Archivo de implementación del TDA MaxQueue
 * @author Laura Zafra Alarcos, Antonio Manuel de Pablos Pancorbo
 */
#include <stack>
#include "maxqueue.h"


void maxqueue::push(int valor) {
    stack<elemento> auxiliar;
    elemento e;
    e.value=valor;
    e.maximum = e.value;

    // Pasar los elementos de principal a auxiliar.
    while (!estavacia(principal)) {
        //Cambiar el maximo de los elementos que correspondan.
        if (e.maximum > principal.top().maximum) principal.top().maximum = e.maximum;
        auxiliar.push(principal.top());
        principal.pop();
    }
    //Insertar el elemento.
    principal.push(e);

    // Pasar los elementos de auxiliar a principal.
    while (!estavacia(auxiliar)) {
        principal.push(auxiliar.top());
        auxiliar.pop();
    }
}


maxqueue::elemento maxqueue::front()const{
    return principal.top();
}

void maxqueue::pop() {
    principal.pop();
}

bool maxqueue::estavacia(stack<elemento> &c) const {
    return c.empty();
}

int maxqueue::tamanio(stack<elemento> &c) const {
    return c.size();
}

