#include <queue>
#include "maxstack.h"

void maxstack::push(int valor){
    queue<elemento> auxiliar;
    elemento e;
    e.value=valor;
    // Pasar los elementos de principal a auxiliar.
    while(!estavacia(principal)){
        auxiliar.push(principal.front());
        principal.pop();
    }
    //Cambiar el maximo del elemento que estamos insertando si corresponde.
    if(estavacia(auxiliar) || e.value>auxiliar.front().maximum)e.maximum=e.value;
    else e.maximum=auxiliar.front().maximum;
    //Insertar el elemento
    principal.push(e);
    //Pasar los elementos de auxiliar a principal.
    while(!estavacia(auxiliar)){
        principal.push(auxiliar.front());
        auxiliar.pop();
    }
}

maxstack::elemento maxstack::top()const{
    return principal.front();
}

void maxstack::pop(){
    principal.pop();
}

bool maxstack::estavacia(queue<elemento> & c)const{
    return c.empty();
}

int maxstack::tamanio(queue<elemento> & c)const{
    return c.size();
}