#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
int _printf(const char *format, ...)
{
va_list ap;
int i;
char *str = malloc(sizeof(char));
if (format == NULL || str == NULL)
{
return (0);
}
va_start(ap, format);
for (i = 0; format[i] != '\0'; i++)
{
if (format[i] == '%' && format[i - 1] != '\\')
{
switch (format[i + 1])
{
case 'c': write(1, va_arg(ap, char *), sizeof(char));
i++;
break;
case 's': write(strlen(va_arg(ap, char *)), va_arg(ap, char *), sizeof(char));
i++;
break;
case '%': write(1, &format[i + 1], sizeof(char));
i++;
break;
}
}
else if (format[i] == '\\')
{
continue;
}
write(1, &format[i], sizeof(char));
}
return (0);
}