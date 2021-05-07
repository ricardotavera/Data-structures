
#include <iostream>
#include <stdio.h>
using namespace std;

using namespace std;


class List
{

  class Node
{
   public:
    
          int num;
          Node *address=NULL;
          
         

  public:
         Node(int pnum)
         {
           num = pnum;
         }
         
       
};

  public: 

//Real definition of List

          short Nodeamount=0;
  private: Node *head = NULL;

  
  public:
         Node* getHead()
         {
           return head;
         }

         void setHead(Node* nod)
         {
            head = nod;
         }

         void addElement(int n)
         {  
            Node *nod = new Node(n);
            Nodeamount++;
            

            if(head==NULL)
            {
              setHead(nod);
              
            }else
            {
              Node *reader;
              for(reader=head; reader->address!=NULL; reader=reader->address);
              reader->address = nod;
            }
          }

          void oddeven()
          {
              List odd;
              List even;
              for(Node *reader=head; reader!=NULL; reader=reader->address)
              {
                if(reader->num%2!=0)
                {
                  odd.addElement(reader->num);
                }else
                {
                  even.addElement(reader->num);
                }
              }
              if(odd.Nodeamount>0)
              {
                cout<<"Odd numbers: "<<odd.Nodeamount<<endl;
                odd.printList();
              }
              if(even.Nodeamount>0)
              {
                cout<<"Even numbers: "<<even.Nodeamount<<endl;
                even.printList();
              }

          }

           void printList()
           { 
             Node *reader = head;
             for(int i=0; i<Nodeamount; i++)
             {
               cout<<reader->num<<endl;
               reader = reader->address;
             }

           }        

};


int main() {
  
  List a;
  for(int i=0; i<50; i++)
  {
    a.addElement((rand()%500)+1);
  }

  a.oddeven();
  
  return 0;
}