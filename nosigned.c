#include "main.h"
#include <unistd.h>
int nosigned(unsigned int n)
{
  unsigned int d, count, len = 0;
  d = n;
  count = 1;
  while (d > 9)
  {
    d /= 10;
    count *= 10;
  }
  for (; count >= 1; count /= 10) {
    int c = ((n / count) % 10) + 48;
    write(1, &c, 1);
    len++;
  }
  return (len);
}