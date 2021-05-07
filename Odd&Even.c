#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>


/*==================Structures Declaraton====================*/
typedef struct node{
 short datum;
 struct node *address;
}*node, typenode;

typedef struct va_list{
  node head;
}*linkedlist, typelist;

/*==================Functions Declaraton======================*/
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

/*=================Functions=======================*/


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
void printList(linkedlist list)
{

  node reading = list->head;
  while (reading!=NULL)
  {
      printf("\n%hd", reading->datum);
      reading = reading->address;
  }
  
}


void oddEven(linkedlist list)
{
    short odd = 0;
    short even = 0;
    for(node reader = list->head; reader!=NULL; reader = reader->address)
    {
      if(reader->datum%2==0)
      {
          odd = 1;
      }else{
          even = 1;
      }
    }

    if(odd==even)
    {
        linkedlist ODD = makeList();
        linkedlist EVEN = makeList();
        for(node reader = list->head; reader!=NULL; reader = reader->address)
    {
      if(reader->datum%2==0)
      {
          addElement(reader->datum, EVEN);
      }else{
          addElement(reader->datum, ODD);
      }
    }
    printf("Odd Numbers: ");
    printList(ODD);
    printf("\nEven Numbers: ");
    printList(EVEN);
    }else{
        if(odd==1)
        {   
            printf("All list is odd");
            printList(list);
        }else
        {
            printf("All list is even");
            printList(list);
        }
        
    }

}



int main()
{
   int i, n;
   time_t t;
   
   n = 30;
   linkedlist list = makeList();
   /* Intializes random number generator */
   srand((unsigned) time(&t));

   /* Print 5 random numbers from 0 to 49 */
   for( i = 0 ; i < n ; i++ ) {
      addElement(rand() % 50, list);
   }

    oddEven(list);
}

    

