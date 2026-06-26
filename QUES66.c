#include <stdio.h>

void value(int a)
{
    a = a + 10;
    printf("Inside Function (Value): %d\n", a);
}

void reference(int *a)
{
    *a = *a + 10;
    printf("Inside Function (Reference): %d\n", *a);
}

int main()
{
    int x = 5;

    value(x);
    printf("After Call by Value: %d\n", x);

    reference(&x);
    printf("After Call by Reference: %d\n", x);

    return 0;
}