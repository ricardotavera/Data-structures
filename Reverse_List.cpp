
#include <iostream>
#include <stdio.h>
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

         void push(Node* nod)
         {
           nod->address=head;
           setHead(nod);
         }

         void reverse()
         {
           List R;
           Node *reader;
           while(head!=NULL)
           {
             reader=head;
             head=head->address;
             R.push(reader);
           }
           
           setHead(R.getHead());
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

           void printList()
           { 
             Node *reader = head;
             for(int i=0; i<Nodeamount; i++)
             {
               cout<<"Data: "<<reader->num<<" Address: "<<reader<<endl;
               
               reader = reader->address;
             }

           }        

};


int main()
{

  List a;
  for(int i=0; i<5; i++)
  {
    a.addElement((rand()%500)+1);
  }
  a.printList();
  a.reverse();
  cout<<"---------------------------"<<endl;
  a.printList();

  
  
  return 0;
}