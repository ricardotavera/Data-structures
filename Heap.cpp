#include <iostream>
#include <stdlib.h>
#include <array>
#include <math.h>


 using namespace std;
 

 int MAX = 100;

 int parent(int);
 void maxHeapyfy(int*, int);
 void minHeapyfy(int*, int);


int rand_seed=10;

/* from K&R
 - produces a random number between 0 and 32767.*/
int rand()
{
    rand_seed = rand_seed * 1103515245 + 12345;
    return (unsigned int)(rand_seed / 65536) % 32768;
}

  // Heap functions
  int parent(int i)
  {
      return (int) (i-1)/2;
  }

  int childLeft(int i)
  {
      return i*2+1;
  }

  int childRight(int i)
  {
      return i*2 +2;
  }
  
  void swap(int *a, int *b)
  {
      int t = *a;
       *a = *b;
       *b = t;
  }


  int emptyHeap(int *A)
  {
      if(A==NULL) 
      {
          return 1;
      }
      else
      {
          return 0;
      }
  }

  int randomNum(int limit)
  {
      return (int) (rand() % limit)+1;
  }

 void buildMaxHeap(int *A)
 {                           
     
     for(int i=(int)(MAX/2); i>=0; i--)
     {
         maxHeapyfy(A, i);
     }      
 }



 void maxHeapyfy(int *A, int i)
 {  
    
    int l, r, largest;
    l = childLeft(i);
    r = childRight(i);
    if(l<MAX && A[l]>A[i])
    {
        largest = l;
    }else
    {
        largest = i;
    }
    
    if(r<MAX && A[r]>A[largest])
    {
        largest = r;
    }

    if(largest!=i)
    {
        swap(&A[i], &A[largest]);
        maxHeapyfy(A, largest);
    }
    
 }

 void buildMinHeap(int *A)
 {                           
     
     for(int i=(int) (MAX/2); i>=0; i--)
     {
         minHeapyfy(A, i);
     }      
 }



 void minHeapyfy(int *A, int i)
 {  
    
    int l, r, largest;
    l = childLeft(i);
    r = childRight(i);
    if(l<MAX && A[l]<A[i])
    {
        largest = l;
    }else
    {
        largest = i;
    }
    
    if(r<MAX && A[r]<A[largest])
    {
        largest = r;
    }

    if(largest!=i)
    {
        swap(&A[i], &A[largest]);
        minHeapyfy(A, largest);
    }

 }


 int heapMaximun(int *A)
    {
        return A[0];
    }


int heapMinimun(int *A)
    {
        return A[0];
    }


int heapExtractMax(int *A)
{   
    if(emptyHeap(A))
    {
        cout<<"Under flow"<<endl;
        return 0;
    }

    int max = heapMaximun(A);
    A[0] = A[MAX-1];
    MAX--;
    maxHeapyfy(A, 0);
    return max;
}

int heapExtractMin(int *A)
{  
    if(emptyHeap(A))
    {
        cout<<"Under flow"<<endl;
        return 0;
    }

    int min = heapMinimun(A);
    A[0] = A[MAX-1];
    MAX--;
    minHeapyfy(A, 0);
    return min;
}

void heapIncreaseKey(int *A, int i)
{
    while(i>0 && A[parent(i)]<A[i])
    {
        swap(&A[parent(i)], &A[i]);
        i = parent(i);
    }
}


void maxHeapInsert(int *A, int key)
{
    A[MAX] = key;
    MAX++;
    auto i = MAX - 1;
    heapIncreaseKey(A, i);
}

void heapDecreaseKey(int *A, int i)
{
    while(i>0 && A[parent(i)]>A[i])
    {
        swap(&A[parent(i)], &A[i]);
        i = parent(i);
    }
}


void minHeapInsert(int *A, int key)
{
    A[MAX] = key;
    MAX++;
    auto i = MAX - 1;
    heapIncreaseKey(A, i);
}

void printHeap(int *A)
{
    for(int i=0; i<MAX; i++)
    {
        if(fmod(log2(i+1),2)==0 || fmod(log2(i+1),2)==1)
        {
            cout<<"\nLevel "<<log2(i+1)<<endl;
            
        }
        
        cout<<" "<<A[i];
        
    }
}

void sortMaxHeap(int *A, int lenght)
{
  
  buildMaxHeap(A);

    for(int i=0; i<lenght; i++)
   {
    cout<<heapExtractMax(A)<<endl;
   } 
}

void sortMinHeap(int *A, int lenght)
{
  
  buildMinHeap(A);

    for(int i=0; i<lenght; i++)
   {
    cout<<heapExtractMin(A)<<endl;
   } 
}
        

 int main()
 {
   cout<<"The function buildMinHeap() is inside of sortMinHeap()"<<endl;
   int *A = new int[MAX];
   for(int i=0; i<MAX; i++)
   {
       A[i] = rand();	
       cout<<A[i]<<endl;
   }
   cout<<"------------------------"<<endl;
   sortMinHeap(A, MAX);
   
   return 0;
 }