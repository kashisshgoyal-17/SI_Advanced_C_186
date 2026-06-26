#include <stdio.h>

int main()
{
    int a[5], *p;
    int i, temp;

    p = a;

    printf("Enter 5 elements:\n");

    for(i = 0; i < 5; i++)
        scanf("%d", p + i);

    for(i = 0; i < 2; i++)
    {
        temp = *(p + i);
        *(p + i) = *(p + 4 - i);
        *(p + 4 - i) = temp;
    }

    printf("Reversed array:\n");

    for(i = 0; i < 5; i++)
        printf("%d ", *(p + i));

    return 0;
}