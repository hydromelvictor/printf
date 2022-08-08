#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * swhiteCase - to print white space
 * @c : ...
 * @count : ...
 * @ap : ...
 *
 * Return : Always return 0 on success
 */

int swhiteCase(char c, int count, va_list ap) {
  char s = ' ';
  int j = 0, nbre = 0;
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
    if(str == NULL)
    {
        break;
    }
    while(str[j])
    {
      write(1, &str[j], 1);
      j++;
      count++;
    }
    count++;
    break;
  case '%':
    write(1, &c, 1);
    count++;
    break;
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
  free(str);
  return (count);
}