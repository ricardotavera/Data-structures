#include <iostream>
#include <stdlib.h>
using namespace std;


typedef struct node {
    int priority;
    char data;  
    struct node *sgte;
}nodo, tipoNodo;


struct cola { //Queue definition
    nodo *delante;
    nodo *atras  ;
};


nodo* crearNodo(char car, int pri) { 
    nodo *nuevoNodo = new nodo();    
    nuevoNodo->data = car;
    nuevoNodo->priority = pri;   
    return nuevoNodo;
}

//Enque
void encolar(struct cola &q, char valor, int prioridad ) {
     
    nodo *aux = crearNodo(valor, prioridad);
    aux->sgte = NULL;
     
    if (q.delante == NULL) {
        q.delante = aux;   
    }    
    else {
        (q.atras)->sgte = aux;
    }
        
    q.atras = aux; 
}


void muestraCola(struct cola q, int n) { 
    nodo *aux; 
    int cont=1; //Counter to commas    
    aux = q.delante;       
    while (aux != NULL) {
        cout<<aux->data;
        if(cont<n) cout<<", ";
        aux = aux->sgte;
        cont++;
    }    
}

//Order numbers depending priority
void ordenarPrioridad(struct cola &q) {
    nodo *aux1, *aux2;
    int p_aux;
    char c_aux;
     
    aux1 = q.delante;
     
    while( aux1->sgte != NULL) {
        aux2 = aux1->sgte;
        
        while( aux2 != NULL) {
            if( aux1->priority < aux2->priority ) {
                p_aux = aux1->priority;
                c_aux = aux1->data;
                
                aux1->priority = aux2->priority;
                aux1->data   = aux2->data;
                
                aux2->priority = p_aux;
                aux2->data   = c_aux;
            }
            aux2 = aux2->sgte;
        }
        aux1 = aux1->sgte;
     }
}


void entradaDatos(struct cola &q, char c, int pr) {    
    encolar(q, c, pr);   
    ordenarPrioridad(q); 
}


int main()
{
    struct cola nuevaCola;
    
    nuevaCola.delante = NULL;
    nuevaCola.atras   = NULL;

    char car;
    int i, numero, n;

    cout<<"Input quantity elements: ";
    cin>>n;
   
    cout<<"The data is Input automatically by a random function, so don't worry. You can check the code"<<endl;
    for (i=0; i<n; i++) 
    {
       
        entradaDatos(nuevaCola, 'a' + rand() % (('z' - 'a') + 1), rand()%9+1);
    }
    cout<<endl;
    if(nuevaCola.delante!=NULL) {
        muestraCola(nuevaCola, n);
    }
    
    return 0;
}