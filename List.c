#include <stdio.h>
#include "List.h"
#include <stdlib.h>



//=================Functions=======================


node makeNodo(short a, short b){
  node nodo1 = (node) malloc(sizeof(typenode));
  nodo1->a = a;
  nodo1->b = b;
  nodo1->address = NULL;
  return nodo1;
}

linkedlist makeList(){
 linkedlist listA = (linkedlist) malloc(sizeof(typelist));
 listA->head = NULL;
 return listA;
}

void push(short a, short b, linkedlist list){
 node node1 = makeNodo(a ,b);
 node1->address = list->head;
 list->head = node1;

}

int pop(linkedlist list)
{
  int var[2];
  node node1 = list->head;
  var[0] = node1->a;
  var[1] = node1->b;
  list->head = list->head->address;
  free(node1);

  return var[0];
}

node lastNode(linkedlist list)
{
  node p = list->head;
  node l;
  while(p!=NULL)
  {
   l = p; 
   p = p->address;
  }
  
  return l;
}

void addElement(short a, short b, linkedlist queue)
{
  node node1 = makeNodo(a, b);
  if(queue->head==NULL)
  {
    queue->head = node1;
  }
  else
  {
  lastNode(queue)->address = node1;
  }
}



short listSize(linkedlist list)
{
  node node1 = list->head;
  short size = 0;
  while(node1!=NULL)
  {
    size++;
    node1 = node1->address;
  }
  return size;
}

