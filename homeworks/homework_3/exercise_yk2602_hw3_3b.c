#include <stdio.h>
// the library stdlib.h contains the desired srand() function
#include <stdlib.h>
// the library necessary to declare the time() function as an argument of the srand()
#include <time.h>

int main()
{
    // initialize variables
    int rand_number, i = 0;
    srand((unsigned)time(NULL));
    while (i < 10)
    {
        // generate random number
        rand_number = rand() % 6 + 1;
        // print random number
        printf("%d ", rand_number);
        // increment counter
        i++;
    }
    // add the line break to the end of the output
    printf("\n");
    return 0;
}
