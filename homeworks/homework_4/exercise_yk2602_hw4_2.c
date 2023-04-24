#include <stdio.h>
// Part 1
int linear_search(int a[], int length, int val)
{
    // initialize the iterator
    int i;
    // little for loop to go over the array
    for (i = 0; i < length; i++)
    {
        // catching the first occurrence of the val
        if (a[i] == val)
        {
            // outputing the first occurrence of the val found in the array
            printf("The val %d is found in the array at index %d\n", val, i);
            // returning the index, making sure program exits
            return i;
        }
    }
    printf("The val %d is NOT found in the array\n", val);
    // in case the value of val is not in the array, then function returns -1
    return -1;
}
// Part 2
int is_sorted(int a[], int length)
{
    int i, this, next;

    if (length > 2)
    {
        // assigning the local variable for the comparison purposes
        this = a[0];
        for (i = 1; i < length; i++)
        {
            next = a[i];
            if (next < this)
            {
                // returning false because the array is not sorted
                printf("Oops! Array is not sorted.\n");
                return 0;
            }
            this = next;
        }
        // returning true after traversing the array
        printf("The array is sorted.\n");
        return 1;
    }

    else if (length == 1)
    {
        printf("The array is sorted simply because it contains only one element)\n");
        return 1;
    }

    else
    {
        printf("Sorry, it seems that the array is empty!\n");
        return 0;
    }
}

// this function will be heling my recursion
int helper(int a[], int left, int right, int value)
{
    int middle;
    // integer division to determine the middle index of the array
    middle = (left + right) / 2;
    // checking for the base-case
    if (value == middle)
    {
        return middle - 1;
    }
    else if (value < a[middle])
    {
        right = middle - 1;
        return helper(a, left, right, value);
    }
    else
    {
        left = middle + 1;
        return helper(a, left, right, value);
    }
    // this return will be executed in case the value is not in the array
    return -1;
}

// Part 3
int binary_search(int a[], int length, int val)
{
    int left = 0, right = (length - 1);
    return helper(a, left, right, val);
}
// What may happen when the function binary_search is called with an array which is not sorted ?
// ANSWER: In case the array is not sorted, the binary search does not make sense to work properly.

int main()
{
    int a[5] = {2, 44, 102, 33, 33};
    linear_search(a, 5, 102);

    int b[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    is_sorted(b, 10);
    is_sorted(a, 5);

    int looking_for = 1;
    int temp = binary_search(b, 10, looking_for);
    printf("The index of '%d' is %d\n", looking_for, temp);

    return 0;
}