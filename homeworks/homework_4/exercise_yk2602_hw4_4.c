#include <stdio.h>

// Part 1
// function which computes the power of the given number
int ft_power(int x, int power)
{
    int result = 1;
    for (int i = 1; i <= power; i++)
    {
        result *= x;
    }
    return result;
}

// the function which evaluates the polynimial expresion at the given X
int eval(int x, int a[], int n)
{
    int i, res = 0;

    for (i = 0; i < n; i++)
    {
        // add the multiplication of the coefficient a[i] and the X into the power of I to the result
        // evaluating the value term by term
        res += a[i] * ft_power(x, i); // note that the ft_power is computer every single iteration
    }
    return res;
}

// Part 2
int eval_2(int x, int a[], int n)
{
    int i, res;
    // start with the highest degree coefficient
    res = a[n - 1];
    // lopping the expression over and over again
    for (i = n - 2; i >= 0; i--)
    {
        // multiply by x and add the next coefficient to evaluate the expression
        // this way we only have N multiplications at most
        res = res * x + a[i];
    }
    // returning the evaluated result
    return res;
}

int main()
{
    int x, res, res2, a[] = {1, 2, 3, 4};
    x = 2;
    res = eval(x, a, 4);
    res2 = eval_2(x, a, 4);

    printf("EVAL: evaluated expression at x = %d equals %d\n", x, res);
    printf("EVAL_2: evaluated expression at x = %d equals %d\n", x, res2);
}