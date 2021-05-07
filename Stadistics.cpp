#include <iostream>
#include <math.h>
using namespace std;
void getReading();


void getReading(short n, double data[100])
{
  for(short i=0; i<n; i++)
  {
    cout<<i+1<<" : ";
    cin>>data[i];
  }
}
void orderData(short n, double data[])
{ double temp;
  for(short i=0; i<(n-1); i++)
  {
    for(short j=i+1; j<n; j++)
    {
        if(data[j]<data[i])
        {
          temp=data[i];
          data[i]=data[j];
          data[j]=temp;
        }       
    }
  }
}
double getAverage(double data[], short n)
{ 
  int sum=0;
  for(short i=0; i<n; i++)
  {
    sum=sum+data[i];
  }
  return sum/n;
}
double getMedian(double data[], short n)
{ double median;
  if(n%2==0)
  {
   median=data[(n/2)-1]+data[n/2];
  }else
  {
    median=data[(n-1)/2];
  }
  return median;
}
double getMode(double data[], short n)
{ double mode;
  short cmode, cpmode;
  cmode=0;
   
  for(short i=0; i<n; i++)
  { cpmode=0;
    for(short j=0; j<n; j++)
    {
      if(data[i]==data[j])
      {
        cpmode++;
      }
      if(cpmode>cmode)
      {
        cmode=cpmode;
        mode=data[i];
      }
    }
    
    //cout<<data[i]<<endl;
    
  }
  
  return mode;
}

double getStandardes(double data[], short n)
{ 
  double s,mean;
  mean=getAverage(data,n);
  s=0;
  for(short i=0; i<n; i++)
  {
    s=s+(data[i]-mean)*(data[i]-mean)/(n-1);
  }
  s=sqrt(s);
  return s;
}


int main() {
  short n;
  int *p;
  int a;
  p=&a;
  cout<<"Amount: ";
  cin>>n;
  double data[n];

  getReading(n, data);
  orderData(n, data);
  cout<<"Mean: "<<getAverage(data, n)<<endl;
  cout<<"Median: "<<getMedian(data, n)<<endl;
  cout<<"Mode: "<<getMode(data, n)<<endl;
  cout<<"Standard Desviation: "<<getStandardes(data, n)<<endl;
  printf("%ld\n", sizeof(n));
  printf("p=%p, *p=%d\n", p, *p);
  --p;
  printf("p=%p\n", p);
  --p;
  printf("p=%p\n", p);
  p=p+1;
  printf("p=%p\n", p);
  
  system("pause");
  

}