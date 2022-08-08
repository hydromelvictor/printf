#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
/**
 * _print - Print character according to format
 * @format : format to print
 * @... - .....
 *
 * Return : Always return 0 (on success)
 */
int _printf(const char *format, ...)
{
va_list ap;
int i = 0, charCount = 0;
if(format == NULL)
{
return (charCount);
}
va_start(ap, format);
while(format[i])
{
if(format[i] == '%')
{
if(format[i + 1])
{
i++;
charCount++;
}
charCount += swhiteCase(format[i], charCount, ap);
i++;
}
write(1, &format[i], 1);
i++;
charCount++;
}
va_end(ap);
return (charCount);
}