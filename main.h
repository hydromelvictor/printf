#ifndef _MAIN_H
#define _MAIN_H
#include <stdarg.h>
int _printf(const char *format, ...);
int number(int n) ;
int swhiteCase (char c, int count, va_list ap);
int binary(unsigned int n);
int octal(unsigned int n);
int hexal(unsigned int n, char c);
#endif