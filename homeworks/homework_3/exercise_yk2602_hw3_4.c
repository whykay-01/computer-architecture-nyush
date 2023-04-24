#include <stdio.h>

int main()
{
  // initialize variables
  int n, i;
  long int num_a = 0, num_b = 1, output_num;

  // ask and scan for the length of the sequence
  printf("Enter the number: ");
  scanf("%d", &n);

  // generating fibonacci numbers and printing them
  for (i = 1; i <= n; i++)
  {
    printf("%ld ", num_a);
    output_num = num_a + num_b;
    num_a = num_b;
    num_b = output_num;
  }
  // classic return statement of the int function
  return 0;
}
