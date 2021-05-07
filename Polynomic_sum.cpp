#include <iostream>
#include <stdio.h>
#include <string.h>


using namespace std;
class linkedlist
{
    class node
    {
      public:
             short a, b;
             node *address=NULL;
      public:
            node(short pa, short pb)
            {
               a = pa;
               b = pb;
            }
    };

    public: short Nodeamount = 0;
    private: node *head=NULL;

    public:
            node* getHead()
            {
              return head;
            }

            void setHead(node *nod)
            {
              head = nod;
            }

            void addElement(short a, short b)
            {
              node *nod = new node(a, b);
              if(head==NULL)
              {
                head = nod;
              }else
              {
                node *reader;
                for( reader=head; reader->address!=NULL; reader=reader->address){}
                reader->address = nod;
                
              }
            }

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

void flist(char *str)
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
     
     addElement(a, b);
     s = i+1;
   }
       
  }
  
  
}



void sort()
{
   int t;

  for(node *d = head; d->address!=NULL; d = d->address)
  {
    
     for(node *p = d->address; p!=NULL; p = p->address)
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
        
}

void showList()
{
  
   for(node *d = head; d!=NULL; d = d->address)
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

void sum(linkedlist* l1, linkedlist* l2)
{
    
    short aux;
    for(node *d = l1->head; d!=NULL; d = d->address)
    {
       aux = 0;
       for(node *p = l2->head; p!=NULL; p = p->address)
       {
          if(d->b == p->b)
          {
             addElement(d->a+p->a, d->b);
              aux = 1;
          }

       }
        if(aux==0)
        {
           addElement(d->a, d->b);
        }
    }

    for(node *d = l2->head; d!=NULL; d = d->address)
    {
       aux = 0;
       for(node *p = head; p!=NULL; p = p->address)
       {
          if(d->b == p->b)
          { 
              aux = 1;
          }
       }

       if(aux==0)
       {
          addElement(d->a, d->b);
       }
    
    }

}

void printList()
{
  for(node *d = head; d!=NULL; d = d->address)
  {
    printf("\na: %d  b: %d   address: %p", d->a, d->b, d);
  }
}

};


int main()
{
  
   string x  = "265xe38+5x-9xe7+1000";
   string y  = "15x+2xe3+3xe7";
  
  char *p = const_cast<char*>(x.c_str());
  char *q = const_cast<char*>(y.c_str());

  linkedlist a;
  linkedlist b;
  linkedlist c;
  
  a.flist(p);
  b.flist(q);
  
  
  c.sum(&a, &b);
  c.sort();
  c.showList();
  
 return 0;
}