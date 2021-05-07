#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

//==================Structures Declaraton====================
typedef struct node{
 char datum;
 struct node *address;
}*node, typenode;

typedef struct va_list{
  node head;
}*linkedlist, typelist;

//==================Functions Declaraton======================
linkedlist makeList();
node makeNodo(char);
void push(char, linkedlist);
void nodePush(node, linkedlist);
void printList(linkedlist);


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

void push(char n, linkedlist list){
 node node1 = makeNodo(n);
 node1->address = list->head;
 list->head = node1;

}



void add(char n, linkedlist list){
 node node1 = makeNodo(n);
 if(list->head==NULL)
 {
   list->head =  node1;
 }else{
 node reader = list->head;
 while(reader->address!=NULL)
 {
   reader = reader->address;
 }
 reader->address = node1;
 }
 

}

void nodePush(node node1, linkedlist list)
{
  //node1->address = list->head;
  list->head = node1;
}
linkedlist reverse(linkedlist list)
{
  node reader;
  linkedlist R = makeList();
  while(list->head!=NULL)
  {  
     reader = list->head;
     list->head = list->head->address;
     reader->address = R->head;
     R->head = reader;
     
  }
  list->head = R->head;
  return list;
}

void printList(linkedlist list)
{
  printf("\nHead address %p", list->head);
  for(node reader = list->head; reader!=NULL; reader = reader->address )
  {
    printf("\nData: %c  address: %p", reader->datum, reader->address);
  }
}
int main(void) {
  
  char *word;
   linkedlist A = makeList();
  printf("Type words: ");
  scanf("%s", word);
  for(int i=0; i<strlen(word); i++)
  {
    add(word[i],A);
  }
  
  printList(A);
  reverse(A);
  printList(A);
 

}