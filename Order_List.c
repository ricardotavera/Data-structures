#include <stdio.h>
#include <stdlib.h>

//==================Structures Declaraton====================
typedef struct node {
 float datum;
 struct node *address;
}*node, typenode;

typedef struct va_list{
  node head;
}*linkedlist, typelist;


//==================Functions Declaraton======================
linkedlist makeList();
node makeNodo(float);
void push(float, linkedlist);
void insert(float, short, linkedlist);
node element(short, linkedlist);
short seekPos(float value, linkedlist);
void add(float, linkedlist);
void addElement(float, linkedlist);
void printList(linkedlist);

// main
int main()
{ 

  float input;
  linkedlist A = makeList();

  for(int j=0; j<5; j++)
  { 
    
    scanf("%f", &input );
    addElement(input, A);
    printList(A);
  
  }
 
  

  return 0;
}


//Functions
linkedlist makeList();
node makeNodo(float);

node makeNodo(float value){
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

void push(float n, linkedlist list)
{
 node node1 = makeNodo(n);
 node1->address = list->head;
 list->head = node1;
}


void addElement(float n, linkedlist list)
{
	node nod = makeNodo(n);
  node reader;
	if(list->head == NULL)
	{
		list->head = nod;
	}else
	{
		if(nod->datum<=list->head->datum)
		{
			nod->address = list->head;
			list->head = nod;
		}else
		{
			for(reader = list->head; reader->address!=NULL; reader = reader->address)
			{
				if(nod->datum<=reader->address->datum)
				{
					nod->address = reader->address;
					reader->address = nod;
					break;
				}
        
			}
			if(reader->address==NULL)
			{
				reader->address = nod;
			}
		}
	}
}
void printList(linkedlist list)
{
	for(node reader = list->head; reader!=NULL; reader = reader->address)
	{
		
    printf("\n %f", reader->datum);
  
	}
}

