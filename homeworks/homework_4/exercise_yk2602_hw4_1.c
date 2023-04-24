// essential library which enables the printf and scanf functions
#include <stdio.h>
// Part 1
void print_array(int a[], int n)
{
    int i = 0;
    printf("Here is the array: ");
    // read element by element from the array, and print it
    for (i = 0; i < n; i++)
        // printing the element and the space after it
        printf("%d ", a[i]);
    // breaking line
    printf("\n");
    // void return
    return;
}
// Part 2
void read_array(int a[], int n)
{
    int i = 0;
    // small GUI element here
    printf("Enter %d integers\n", n);
    // little loop to do the repetitive scanning of the values
    for (i = 0; i < n; i++)
    {
        // instructions for the user
        printf("Enter int #%d, and hit the Enter key\n", i + 1);
        // waiting for the user to enter
        scanf("%d", &a[i]);
    }
    // void return
    return;
}
// Part 3
int main()
{
    // initialization of the array
    int a[5];
    // calling the function to insert the values into the array
    read_array(a, 5);
    // printing the values of the array
    print_array(a, 5);
    // classic return statement
    return 0;
}
