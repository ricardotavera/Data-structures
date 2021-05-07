
#include <iostream>

using namespace std;




typedef struct node{
 char d; //datum
 struct node *l; //left child
 struct node *r; //right child
}node, typenode; 

 node* trunk = NULL;
 int i = 0;

node* makeNode(char);
void insert(node *&, char*);
void preorder(node*);
void posorder(node*);
void inorder(node*);


void inorder(node *tree)
{
  if(tree==NULL)
  {
    return;

  }else
  {
    inorder(tree->l);
    cout<<"  "<<tree->d;
    inorder(tree->r);
    
  }
}


void posorder(node *tree)
{
  if(tree==NULL)
  {
    return;

  }else
  {
    posorder(tree->l);
    posorder(tree->r);
    cout<<"  "<<tree->d;
  }
}


void preorder(node *tree)
{
  if(tree==NULL)
  {
    return;

  }else
  {
    cout<<"  "<<tree->d;
    preorder(tree->l);
    preorder(tree->r);
  }
}

void insert(node *&tree, char *A)
{

   

  if(A[i]!='#')
  {

  

   i++;
   insert(tree->l, A);

if(tree==NULL) //check if the tree is empty
  {
     node *nod = makeNode(A[i]);
     tree = nod;
  }
   i++;
   insert(tree->r, A);

  }
  
 
} 

node* makeNode(char n)
{
  node *nod = new node();
  nod->d = n;
  nod->l = NULL;
  nod->r = NULL;

  return nod;
}


int main() {

/*  
string preorderTree;
cout<<"Input preorderTree";
cin>>preorderTree;
*/
 char pret[17] = {'a','b','#','c','d','#','#','e','f','#','#','#','g','i','#','#','#'};



 insert(trunk, pret);
 posorder(trunk);
 

  return 0; 
}
