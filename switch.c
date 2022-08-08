#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int print(char *str)
{
  int j = 0, count = 0;
    if(str == NULL)
    {
        return 0;
    }
    while(str[j])
    {
      write(1, &str[j], 1);
      j++;
      count++;
    }
    return count;
}

int wordSwitch(char c, va_list ap)
{
  int count = 0;
  char s = ' ';
  char *str = malloc(sizeof(char));
  if (str == NULL) {
    return (count);
  }
  switch (c)
  {
  case 'c':
    s =(char) va_arg(ap, int);
    if(str == NULL)
    {
        break;
    }
    write(1, &s, 1);
    count++;
    break;
  case 's':
    *str = *va_arg(ap, char *);
    count += print(str);
    break;
  }
  return (count);
}

int numberSwitch(char c, va_list ap)
{
   int nbre = 0, count  = 0;
  switch (c)
  {
  case 'i':
    nbre = va_arg(ap, int);
    count += number(nbre);
    count++;
    break;
  case 'd':
    nbre = va_arg(ap, int);
    count += number(nbre);
    count++;
    break;
  }
  return count;
}

int nodecimalCase(char c, va_list ap)
{
  int count = 0, nbre = 0;
    switch (c)
  {
  case 'b':
    nbre = va_arg(ap, int);
    count += binary(nbre);
    count++;
    break;
  case 'o':
    nbre = va_arg(ap, unsigned int);
    count += octal(nbre);
    count++;
    break;
  case 'x':
    nbre = va_arg(ap, unsigned int);
    count += hexal(nbre, 'x');
    count++;
    break;
  case 'X':
    nbre = va_arg(ap, unsigned int);
    count += hexal(nbre, 'X');
    count++;
    break;
 case 'u':
    nbre = va_arg(ap, unsigned int);
    count += nosigned(nbre);
    count++;
    break;
  }
  return count;
}

/**
 * swhiteCase - to print white space
 * @c : ...
 * @count : ...
 * @ap : ...
 *
 * Return : Always return 0 on success
 */
int swhiteCase(char c, int count, va_list ap) {
  char *str = malloc(sizeof(char));
  if (str == NULL) {
    return (count);
  }
  if(c == 'c' ||c =='s')
  {
    count += wordSwitch(c, ap);
  }
  if(c=='i' || c=='d')
  {
   count += numberSwitch(c, ap);
  }
  if(c=='b' || c=='o' || c=='x' || c=='X' || c=='u')
  {
    nodecimalCase(c, ap);
  }
  if(c =='%')
  {
    write(1, &c, 1);
    count++;
  }
  free(str);
  return (count);
}