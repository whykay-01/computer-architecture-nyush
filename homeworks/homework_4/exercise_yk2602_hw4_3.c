#include <stdio.h>
// Part 1
void insertion_sort(int a[], int n)
{
    // initialize the variables
    int m = 1, j = 0, temp = 0;
    // outer loop will run until we sort all the elements of the array
    while (m < n)
    {
        // store the reference j to the element previous to the current element we want to place
        // in the right place
        j = m - 1;
        // looping through the sorted m-1 elements of the array to put the current element
        // in the correct place
        while (j >= 0 && a[m] < a[j])
        {
            // manipulating the current element
            temp = a[m];
            a[j + 1] = a[j];
            a[j] = temp;
            m = j;
            // decrement the j reference to reach the correct position in the array
            j--;
        }
        // incrementing the m reference
        m++;
    }
}
// Part 2
int main()
{
    int i, n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter the elements of the array:\n");
    // reading the elements from the terminal and storing them in the array
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    // calling the function to perform the sorting algorithm
    insertion_sort(a, n);
    printf("The sorted array is:\n");
    // outputing the elements of the array element by element
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    // breaking line
    printf("\n");
    // classic return statement
    return 0;
}
