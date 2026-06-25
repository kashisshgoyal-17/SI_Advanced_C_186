#include<stdio.h>

int main()
{
    int a[5], i, max, min;

    for(i=0;i<5;i++)
        scanf("%d",&a[i]);

    max = min = a[0];

    for(i=1;i<5;i++)
    {
        if(a[i] > max)
            max = a[i];

        if(a[i] < min)
            min = a[i];
    }

    printf("Largest = %d\n", max);
    printf("Smallest = %d", min);

    return 0;
}