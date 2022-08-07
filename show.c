#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
int _printf(const char *format, ...)
{
va_list ap;
int i = 0, charCount = 0;
if(format == NULL)
{
return (charCount);
}
va_start(ap, format);
for (i = 0; format[i] != '\0'; i++, charCount++)
{
if(format[i] == '%' && format[i - 1] != '\\')
{
if(format[i + 1] != '\0')
{
i++;
charCount++;
}
charCount += swhiteCase(format[i], charCount, ap);
i++;
}
else if (format[i] == '\\')
{
continue;
}
write(1, &format[i], sizeof(char));
}
return (charCount);
}