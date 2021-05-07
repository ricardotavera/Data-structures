
#include "Stack.h"

//=================Functions=======================


node makeNodo(char value){
  node nodo1 = (node) malloc(sizeof(typenode));
  nodo1->datum = value;
  nodo1->address = NULL;
  return nodo1;
}

linkedlist makeList(){
 linkedlist listA = (linkedlist) malloc(sizeof(typelist));
 listA->head = NULL;
 return listA;
}

void add(char n, linkedlist list){
 node node1 = makeNodo(n);
 node1->address = list->head;
 list->head = node1;

}

char pop(linkedlist list)
{
  char value;
  node element = list->head;
  value = element->datum;
  list->head = element->address;
  free(element);
  return value;
}