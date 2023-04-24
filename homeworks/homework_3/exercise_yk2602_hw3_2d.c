#include <stdio.h>

int main()
{
  // since the factorial cannot be negative, it is better to declare long unsigned int
  // to allocate more memory

  unsigned long int res = 1;
  int i = 1;

  // basic while loop to calculate the factorial
  while (i <= 20)
  {

    res = res * i;
    // outpu each factorial for the user
    printf("%d! = %lu\n", i, res);
    i++;
  }

  return 0;
}