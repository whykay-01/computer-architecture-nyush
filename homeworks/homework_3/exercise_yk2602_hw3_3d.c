#include <stdio.h>
// the library stdlib.h contains the desired srand() function
#include <stdlib.h>
// the library necessary to declare the time() function as an argument of the srand()
#include <time.h>

int main()
{
    // initialize variables
    int rand_number, i, j, counter_6;
    i = j = counter_6 = 0;
    srand((unsigned)time(NULL));
    // add the for loop to print the line of 10 random numbers 10 times
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            // generate random number
            rand_number = rand() % 6 + 1;
            if (rand_number == 6)
            {
                counter_6++;
            }
            // print random number
            printf("%d ", rand_number);
        }
        // add the line break to the end of the output
        printf("\n");
    }
    printf("\n");
    printf("There are %d times when the number '6' is encountered in this matrix.\n", counter_6);
    return 0;
}
