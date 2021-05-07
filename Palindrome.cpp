
#include <iostream>
#include <stdio.h>


using namespace std;

class List
{

  class Node
{
   public:
    
          char data;
          Node *address=NULL;
          
         

  public:
         Node(char pdata)
         {
           data = pdata;
         }
         
       
};

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

         void addElement(char ch)
         {
           Nodeamount++;
            Node *nod = new Node(ch);
            nod->address = head;
            setHead(nod);

         }

         short palindrome(string word)
         {
           short r = 1;
           Node *reader = head;
           for(int i=0; i<Nodeamount; i++)
           {
            if(word[i]!=reader->data)
            {
              r = 0;
              return r;
            }
            reader = reader->address;
           }

           return r;
         }

          void printList()
           { 
             Node *reader = head;
             for(int i=0; i<Nodeamount; i++)
             {
               cout<<reader->data<<endl;
               reader = reader->address;
             }

           }  

  
};

short List::Nodeamount = 0;


int main()
{
  List stack;
  string ph;
  cout<<"Input the word:";
  cin>>ph;

  for(int i=0; i<ph.length(); i++)
  {
    stack.addElement(ph[i]);
  }
  if(stack.palindrome(ph)==1)
  {
    cout<<"It's a palindrome."<<endl;
  }else
  {
    cout<<"It's not a palindrome."<<endl;
  }

  return 0;
}

  