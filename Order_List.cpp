
#include <iostream>
#include <stdio.h>
using namespace std;

using namespace std;


class List
{

  class Node
{
   public:
    
          float num;
          Node *address=NULL;
          
         

  public:
         Node(float pnum)
         {
           num = pnum;
         }
         
       
};

  public: 

//Real definition of List

          static short Nodeamount;
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

         void addElement(float n)
         {  
            Node *nod = new Node(n);
            Nodeamount++;
            

            if(head==NULL)
            {
              setHead(nod);
              
            }else
            {
              if(head->num>=nod->num)
              {
                nod->address = head;
                setHead(nod);
              
                
                
              }else
              {
                Node *reader;
                for(reader=head; reader->address!=NULL; reader=reader->address)
                {
                  if(nod->num<=reader->address->num)
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

short List::Nodeamount = 0;

int main() 
{
 List A;
 float r[] = {2.1,6.3,7.3,8.1,0.2,7.4};
 for(int i=0; i<6; i++)
 {
   
   A.addElement(r[i]);
   A.printList();
   cout<<"-------------------------------"<<endl;
 }
 
 return 0; 
}
