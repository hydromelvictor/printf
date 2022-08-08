#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int octal(unsigned int n)
{
    int i = 0, count = 0;
    unsigned int *t = malloc(sizeof(unsigned int));
    if(t == NULL)
    {
    return 0;
    }
    if(n < 8)
    {
        *t = n;
        count++;
    }
    else
    {
        while (n >= 8)
        {
            t[i]= n % 8;
            n /= 8;
            i++;
            count++;
        }
        t[i] = n;
    }
    for(; i >= 0; i--)
    {
        unsigned int c = t[i] + '0' ;
        write(1, &c, sizeof(unsigned int));
    }
    return (count);
}