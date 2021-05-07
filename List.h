#include <stdio.h>

typedef struct node{
 short a;
 short b;
 struct node *address;
}*node, typenode;

typedef struct va_list{
  node head;
}*linkedlist, typelist;

typedef enum {false, true} bool;

//==================Functions Declaraton======================
extern linkedlist makeList();
extern node makeNodo(short, short);
extern void push(short, short, linkedlist);
extern int pop(linkedlist);
extern node lastNode(linkedlist);
extern void insertLast(short, short linkedlist);
extern short last(linkedlist);
extern node element(short, linkedlist);
extern void deleteLast(linkedlist);
extern short listSize(linkedlist);
extern void addElement(short, short, linkedlist);


