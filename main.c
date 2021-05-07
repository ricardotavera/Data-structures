#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
#include <string.h>

short palindrome(char*);
short palindrome(char *ph)
{
    short n = strlen(ph);
    linkedlist stack = makeList();
    short r = 1;

    if(n%2==0)
    {
        for(int i=n/2; i<n; i++)
        {
            add(ph[i], stack);
        }
    }else
    {
        for(int i=(int) (n/2)+1; i<n; i++)
        {
            add(ph[i], stack);
        }
    }
    
    for(int k=0; k<n/2; k++)
    {
        if(ph[k]!=pop(stack))
        {
            r = 0;
            return r;
        }

    }

    return r;
}


int main()
{
    char *palin = (char*) malloc(1);
    printf("Type the phrase: ");
    scanf("%s", palin);
    
    if(palindrome(palin)==1)
    {
        printf("It's  a palindrome");
    }else
    {
        printf("It's not a palindrome");
    }

    return 0;
}