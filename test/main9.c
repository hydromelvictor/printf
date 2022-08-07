#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include "../main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    unsigned int ui;
    ui = (unsigned int)INT_MAX + 1024;
    _printf("moi Unsigned octal:[%o]\n", ui);
    printf("Unsigned octal:[%o]\n", ui);
    return (0);
}