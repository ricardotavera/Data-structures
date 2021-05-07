#include <iostream>
#include <string.h>

using namespace std;

#define MAX 100
 
//Data structures and function definitions
typedef struct nodo {
    char valor; 
    struct nodo *izquierda; 
    struct nodo *derecha; 
}nodo, tipoNodo;

nodo* arbol = NULL;


void inOrden(nodo *arbol) {
    if (arbol == NULL) {
        return;
    }
    else {
        inOrden(arbol->izquierda);
        cout<<arbol->valor<<" ";
        inOrden(arbol->derecha);
    }
}

