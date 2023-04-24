// library for the input and output commands to be working in the program
#include <stdio.h>
// declaring the type of the variable n
int n;

int main()
{
  // waiting for the input from the user
  printf("Input the integer: ");
  scanf("%d", &n);
  // condition catching the regular numbers (everything except for the 42 --> lost is outputed)
  if (n != 42)
  {
    printf("lost\n");
  }
  // output if we are succesful
  else
  {
    printf("well done\n");
  }
  // classic return statement of the int function
  return 0;
}
