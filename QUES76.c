#include <stdio.h>

int main()
{
    int a[5], b[5], *p1, *p2;
    int i, temp;

    p1 = a;
    p2 = b;

    printf("Enter first array:\n");
    for(i = 0; i < 5; i++)
        scanf("%d", p1 + i);

    printf("Enter second array:\n");
    for(i = 0; i < 5; i++)
        scanf("%d", p2 + i);

    for(i = 0; i < 5; i++)
    {
        temp = *(p1 + i);
        *(p1 + i) = *(p2 + i);
        *(p2 + i) = temp;
    }

    printf("First array:\n");
    for(i = 0; i < 5; i++)
        printf("%d ", *(p1 + i));

    printf("\nSecond array:\n");
    for(i = 0; i < 5; i++)
        printf("%d ", *(p2 + i));

    return 0;
}