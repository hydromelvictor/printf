#include "main.h"
#include <unistd.h>
/**
 * number - print number
 * @n : number to print
 *
 * Return : Always return 0 (on succes)
 */

int number(int n)
{
  unsigned int m, d, count, len = 0;
  if (n < 0)
  {
    int c = 45;
    write(1, &c, 1);
    len++;
    m = n * -1;
  }
  else
  {
    m = n;
  }
  d = m;
  count = 1;
  while (d > 9)
  {
    d /= 10;
    count *= 10;
  }
  for (; count >= 1; count /= 10) {
    int c = ((m / count) % 10) + 48;
    write(1, &c, 1);
    len++;
  }
  return (len);
}