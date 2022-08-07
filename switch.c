#include "main.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
int swhiteCase (char c, int count, va_list ap)
{
char *str = malloc(sizeof(char));
int j, nbre = 0;
if(str == NULL)
{
return (count);
}
switch (c)
{
case 'c': str = va_arg(ap, char *);
write(1, &str, sizeof(char));
count++;
break;
case 's': str = va_arg(ap, char *);
for(j = 0; str[j] != '\0'; j++, count++)
{
write(1, &str[j], sizeof(char));
}
count++;
break;
case '%':
write(1, &c, sizeof(char));
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
}
 return (count);
}