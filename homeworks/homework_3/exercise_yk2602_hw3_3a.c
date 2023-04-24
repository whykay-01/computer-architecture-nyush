#include <stdio.h>
// the library stdlib.h contains the desired srand() function
#include <stdlib.h>
// the library necessary to declare the time() function as an argument of the srand()
#include <time.h>

int main()
{
  // this code is now compiled
  srand((unsigned)time(NULL));
  printf("%d\n", rand() % 10 + 1);
  printf("%d\n", rand() % 10 + 1);

  return 0;
}
