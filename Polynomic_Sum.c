#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "List.h"

char *subString(char*, int , int );
linkedlist flist(linkedlist, char*);
linkedlist sum(linkedlist, linkedlist);
linkedlist sort(linkedlist);
void showList(linkedlist);
int Index(char*, char);
bool itis(char, char*);


char *subString(char *str, int f, int l)
{ 
  
  int n = (l-f)+1;
  char *sub = (char*)malloc(n);
  for(int i=0; i<n; i++)
  {
     sub[i] = str[f];
     f++;
  }

  return sub;

}

int Index(char *str, char a)
{
   for(int i=0; i<strlen(str); i++)
   {
      if(str[i]==a) return i;
   }
   return 0;
}


bool itis(char c, char *str)
{  
   bool x = false;
   for(int i=0; i<strlen(str); i++)
   {
       if(str[i]==c)
       {
          x = true;
       }
   }
   return x;
}

linkedlist flist(linkedlist p, char *str)
{
  
  short s, a, b, n, x;
  s = 0;
  char *r = (char *) malloc(1);
  for(short i=1; i<=strlen(str); i++)
  {
     if(str[i]=='+' || str[i]=='-' || i==strlen(str))
     {  
        r = subString(str, s, i-1);
        if(itis('x', r))
        {    
            
             n = strlen(r);
             x = Index(r, 'x');
              if(r[n-1]=='x')
        {
           b=1;
           if(r[0]=='x')
           {
              a = 1;
           }else
           {
              a = atoi(subString(r, 0, x-1));
           }
       }else
       {
          b = atoi(subString(r, x+2, n-1));

          if(r[0]=='x')
          {
             a = 1;
          }else
          {
             a = atoi(subString(r, 0, x-1));
          }
          
       }
          if(s>0 && str[s-1]=='-')
          {
             a = a*(-1);
          }
            
            
       
       
     }else
     {
       
        a = atoi(r);
        b = 0;
        
        if(s>0 && str[s-1]=='-')
        {
           a = -1*a;
        }


     }
     
     addElement(a, b, p);
     s = i+1;
   }
       
  }
  
  return p;
}

linkedlist sum(linkedlist l1, linkedlist l2)
{
    linkedlist sum = makeList();
    short aux;
    for(node d = l1->head; d!=NULL; d = d->address)
    {
       aux = 0;
       for(node p = l2->head; p!=NULL; p = p->address)
       {
          if(d->b == p->b)
          {
             addElement(d->a+p->a, d->b, sum);
              aux = 1;
          }

       }
        if(aux==0)
        {
           addElement(d->a, d->b, sum);
        }
    }

    for(node d = l2->head; d!=NULL; d = d->address)
    {
       aux = 0;
       for(node p = sum->head; p!=NULL; p = p->address)
       {
          if(d->b == p->b)
          { 
              aux = 1;
          }
       }

       if(aux==0)
       {
          addElement(d->a, d->b, sum);
       }
    
    }
return sum;
}

linkedlist sort(linkedlist l)
{
   int t;

  for(node d = l->head; d->address!=NULL; d = d->address)
  {
    
     for(node p = d->address; p!=NULL; p = p->address)
     {
       
        if(d->b < p->b)
        {
           t = p->b;
           p->b = d->b;
           d->b = t;

           t = p->a;
           p->a = d->a;
           d->a = t;

        }
     }
  }
        return l;
}

void showList(linkedlist list)
{
  
   for(node d = list->head; d!=NULL; d = d->address)
   {
      if(d->a>0)
      {
        printf("+%dx^%d ", d->a, d->b);
      }
      else
      {
        printf("%dx^%d ", d->a, d->b);
      }
    
      
   }
  
}

void printList(linkedlist list)
{
  for(node d = list->head; d!=NULL; d = d->address)
  {
    printf("\na: %d  b: %d   address: %p", d->a, d->b, d);
  }
}


int main()
{
  char *p = (char *) malloc(1);
  char *q = (char *) malloc(1);

  
  printf("Type the first polynomial: ");
  scanf("%s", p);
  printf("Type the second polynomial: ");
  scanf("%s", q);
  
  /*p = "265xe38+5x-9xe7+1000";
  q = "15x+2xe3+3xe7";*/
  
  linkedlist a = makeList();
  linkedlist b = makeList();
  
  flist(a, p);
  flist(b, q);
  linkedlist c = sum(a, b);
  sort(c);
  showList(c);

  

  
 return 0;
}