#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int hexal(unsigned int n, char c)
{
    int i = 0, count = 0;
    int *t = malloc(sizeof(int));
    if(t == NULL)
    {
    return 0;
    } 
    if(n < 16)
    {
        *t = n;
        count++;
    }
    else
    {
        while (n >= 16)
        {
            t[i]= n % 16;
            n /= 16;
            i++;
            count++;
        }
        t[i] = n;
    }
    for(; i >= 0; i--)
    {
        int p = t[i] + '0';
        if(p < 10)
        {
            write(1, &p, sizeof(int));
        }
        else
        {
            char s = ' ';
            switch (p) {
                case 10 : s = (c == 'x') ? 'a' : 'A'; 
                break;
                case 11 :  s = (c=='x') ? 'b' : 'B';
                break;
                case 12 : s = (c=='x') ? 'c' : 'C';
                break;
                case 13 : s = (c=='x') ? 'd' : 'D';
                break;
                case 14 : s = (c=='x') ? 'e' : 'E';
                break;
                case 15 : s = (c=='x') ? 'f' : 'F';
                break;
            }
        write(1, &s, sizeof(char));
        }
    }
    return (count);
}