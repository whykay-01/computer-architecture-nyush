// standard library
#include <stdio.h>

int main()
{
  // declaration of variables, where res is the potential factorial itself
  int res = 1;
  int i = 1;
  // while loop
  while (i <= 10)
  {
    // computation of the factorial value
    res = res * i;
    // output of the factorial value
    printf("%d! = %d\n", i, res);
    // increment to get the loop going
    i++;
  }

  return 0;
}
