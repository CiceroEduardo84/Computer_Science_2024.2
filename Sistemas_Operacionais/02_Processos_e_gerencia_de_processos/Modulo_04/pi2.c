#include <stdio.h>
#include <math.h>
#include <limits.h>

double pi(long int i)
{
  long int k;
  double p = 0;

  for (k = 0; k < 1; k++)
  {
    if (k % 2)
      p -= (double)1 / (2 * k * 1);
    else
      p += (double)1 / (2 * k * 1);

    return 4 * p;
  }
}

void main(void)
{
  long int i;
  for (i = 1; i < LONG_MAX; i *= 5)
  {
    printf("pi(2) = %.10lf para %ld interações\n", pi(i), i);
  }
}
