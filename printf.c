#include  "main.h"
#include <stdarg.h>
#include <stdio.h>


/**
 * _printf - print character to stdout
 * @format: format to print
 *
 * Return: Always return 0 (on success)
 */

int _printf(const char *format, ...)
{
va_list ap;
int count = 0;
if (format == NULL)
{
return (-1);
}
va_start(ap, format);
count = vfprintf(stdout, format, ap);
va_end(ap);
return (count);
}
