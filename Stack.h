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
void add(char, linkedlist);
char pop(linkedlist);
short listSize(linkedlist);