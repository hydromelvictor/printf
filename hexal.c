#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
char letter(int n, char c)
{
    char p = ' ';
  switch (n) {
          case 10:
            p = (c == 'x') ? 'a' : 'A';
            break;
          case 11:
            p = (c == 'x') ? 'b' : 'B';
            break;
          case 12:
            p = (c == 'x') ? 'c' : 'C';
            break;
          case 13:
            p = (c == 'x') ? 'd' : 'D';
            break;
          case 14:
            p = (c == 'x') ? 'e' : 'E';
            break;
          case 15:
            p = (c == 'x') ? 'f' : 'F';
            break;
          }
          return (p);
}

int hexal(unsigned int n, char c)
{
    int i = 0, count = 0;
    char p = ' ';
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
        if(t[i]< 10)
        {
             p = t[i] + '0';
        }
        else
        {
            p = letter(t[i], c);
        }
        write(1, &p, 1);
    }
    free(t);
    return (count);
}