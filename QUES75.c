#include <stdio.h>

int main()
{
    int a[5], *p, i;

    p = a;

    printf("Enter 5 elements:\n");
    for(i = 0; i < 5; i++)
    {
        scanf("%d", p + i);
    }

    printf("Array elements are:\n");
    for(i = 0; i < 5; i++)
    {
        printf("%d ", *(p + i));
    }

    return 0;
}