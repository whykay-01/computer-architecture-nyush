// standard library
#include <stdio.h>

int main()
{
  // declaration of variables, where res is the potential factorial itself
  int res = 1;
  int i = 1;
  // while loop
  while (i <= 20)
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

// ANSWER: regualar int data type is not enough, so the overflow happened when the function computed
// a number greater than the max value of int type
