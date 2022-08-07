#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int hexal(unsigned int n, char c)
{
    int i = 0, count = 0;
    char *t = malloc(sizeof(char));
    if(t == NULL)
    {
    return 0;
    } 
    if(n < 16)
    {
        if(c == 'x')
        {
            *t = (n==10) ? 'a' : (n==11) ? 'b' : (n==12) ? 'c' : (n==13) ? 'd' : (n==14) ? 'e' : 'f';
        }
        else {
        *t = (n==10) ? 'A' : (n==11) ? 'B' : (n==12) ? 'C' : (n==13) ? 'D' : (n==14) ? 'E' : 'F';
        }
        count++;
    }
    else
    {
        while (n >= 16)
        {
            int p = n % 16;
            if(p < 10)
            {
                t[i] = (char) p; 
            }
            else 
            {
                if(c == 'x')
                {
                    *t = (p==10) ? 'a' : (p==11) ? 'b' : (p==12) ? 'c' : (p==13) ? 'd' : (p==14) ? 'e' : 'f';
                }
                else {
                    *t = (p==10) ? 'A' : (p==11) ? 'B' : (p==12) ? 'C' : (p==13) ? 'D' : (p==14) ? 'E' : 'F';
                }
            }
            n /= 16;
            i++;
            count++;
        }
        t[i] = n;
    }
    for(; i >= 0; i--)
    {
        char c = t[i] ;
        write(1, &c, sizeof(char));
    }
    return (count);
}