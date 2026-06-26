#include <stdio.h>

int main()
{
    int a[2][2], b[2][2], c[2][2];
    int *p1, *p2, *p3;
    int i;

    p1 = &a[0][0];
    p2 = &b[0][0];
    p3 = &c[0][0];

    printf("Enter first matrix:\n");
    for(i = 0; i < 4; i++)
        scanf("%d", p1 + i);

    printf("Enter second matrix:\n");
    for(i = 0; i < 4; i++)
        scanf("%d", p2 + i);

    for(i = 0; i < 4; i++)
        *(p3 + i) = *(p1 + i) + *(p2 + i);

    printf("Sum of matrices:\n");

    for(i = 0; i < 4; i++)
    {
        printf("%d ", *(p3 + i));

        if((i + 1) % 2 == 0)
            printf("\n");
    }

    return 0;
}