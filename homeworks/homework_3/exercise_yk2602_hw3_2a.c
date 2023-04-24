// standard library
#include <stdio.h>

int main()
{
  // declaration of variables
  int n;
  int i = 0;
  int fac = 1;
  // waiting for the input from the user
  printf("Input the integer: ");
  scanf("%d", &n);

  // basic loop where we reach the factorial value by incrementing the value every loop
  for (i = 1; i <= n; i++)
  {
    fac = fac * i;
  }
  // output on the terminal of the result
  printf("factorial of %d is: %d\n", n, fac);
  // classic return of the int function
  return 0;
}
