#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

//==================Structures Declaraton====================
typedef struct node{
 short datum;
 struct node *address;
}*node, typenode;

typedef struct va_list{
  node head;
}*linkedlist, typelist;

//==================Functions Declaraton======================
linkedlist makeList();
node makeNodo(short);
void push(short, linkedlist);
short pop(linkedlist);
node lastNode(linkedlist);
void insertLast(short, linkedlist);
short last(linkedlist);
void insert(short, short, linkedlist);
node element(short, linkedlist);
void deleteLast(linkedlist);
short listSize(linkedlist);

//=================Functions=======================


node makeNodo(short value){
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

void push(short n, linkedlist list){
 node node1 = makeNodo(n);
 node1->address = list->head;
 list->head = node1;

}

short pop(linkedlist list)
{
  short value;
  node element = list->head;
  value = element->datum;
  list->head = element->address;
  free(element);
  return value;
}

short last(linkedlist list)
{
  node p = list->head;
  node l;
  while(p!=NULL)
  {
   l = p; 
   p = p->address;
  }
  
  return l->datum;
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

void insertLast(short n, linkedlist list)
{
  node node1 = makeNodo(n);
  lastNode(list)->address = node1;
}

node element(short p, linkedlist list)
{
  
  node node1 = list->head;
  for(short i=1; i<(p-1); i++)
  {
    node1 = node1->address;
  }
 return node1; 
}

void addElement(short n, linkedlist queue)
{
  node node1 = makeNodo(n);
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

linkedlist makequeue(char *ch){
  linkedlist list = makeList();
  short end = strlen(ch)-1;
  short start = end - 3;
  short number;
  char  t[4];
  for(short i=0; i<strlen(ch)/4; i++)
  {
          t[0] = ch[start]; 
          t[1] = ch[start+1];
          t[2] = ch[start+2];
          t[3] = ch[end];
          
    number = atoi(t);
    addElement(number, list);
    end = start-1;
    start = start -4;
  } 
  if (strlen(ch)%4!=0)
  {   
      number = 0;
      char n[strlen(ch)%4];
    for(short i=0; i<strlen(ch)%4; i++)
    {
      n[i] = ch[i];
    }
    number = atoi(n);
    addElement(number, list);
  }

 return list;
}

linkedlist sumlist(linkedlist A, linkedlist B)
{   linkedlist list = makeList();
short res = 0;
short sum = 0;
node postA = A->head;
node postB = B->head;
while(postA!=NULL || postB!=NULL)
{
    if(postA!=NULL) { 
        sum = sum + postA->datum; 
        postA = postA->address;
    }
    if(postB!=NULL) { 
        sum = sum + postB->datum; 
        postB = postB->address;
    }
    sum = sum + res;
    push(sum%10000, list);
    res = sum/10000;
    sum = 0;
}
if(res!=0) { push(res, list);}
    return list;
}

void printList(linkedlist list)
{
  
  node reading = list->head;
  printf("%hd", reading->datum);
   reading = reading->address;
  while (reading!=NULL)
  {   
    if(reading->datum!=0)
    {   
      if(reading->datum>=1000)
      {
         printf("%hd", reading->datum);
         reading = reading->address;
      }else
      {
        if(reading->datum>=100)
        {
         printf("0%hd", reading->datum);
         reading = reading->address;
        }else
        {
          if(reading->datum>=10)
          {
            printf("00%hd", reading->datum);
            reading = reading->address;
          }else
          {
            printf("000%hd", reading->datum);
            reading = reading->address;
          } 
        }
      }
         
    }else
    {
         printf("0000");
         reading = reading->address;
    }
         
     
  }
        
        
}

int main() {


 char *cadena1 = (char *)malloc(sizeof(char));
 printf("Number A: ");
 scanf("%s", cadena1);

 char *cadena2 = (char *)malloc(sizeof(char));
 printf("Number B: ");
 scanf("%s", cadena2);
 
 
 
 linkedlist N1 = makequeue(cadena1);
 linkedlist N2 = makequeue(cadena2);
 linkedlist N3 = sumlist(N1, N2);

 printList(N3);
    
  }
