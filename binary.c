#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int binary(unsigned int n)
{
    int i = 0, count = 0;
    int *t = malloc(sizeof(int));
    if(t == NULL)
    {
    return 0;
    } 
    if(n < 2)
    {
        *t = n;
        count++;
    }
    else
    {
        while (n >= 2)
        {
            t[i]= n % 2;
            n /= 2;
            i++;
            count++;
        }
        t[i] = n;
    }
    for(; i >= 0; i--)
    {
        int c = t[i] + '0';
        write(1, &c, sizeof(int));
    }
    free(t);
    return (count);
}