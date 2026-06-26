#include <stdio.h>

void prime(int n)
{
    int i, count = 0;

    for(i = 1; i <= n; i++)
    {
        if(n % i == 0)
            count++;
    }

    if(count == 2)
        printf("Prime Number");
    else
        printf("Not Prime Number");
}

void armstrong(int n)
{
    int temp, rem, sum = 0;

    temp = n;

    while(temp > 0)
    {
        rem = temp % 10;
        sum = sum + rem * rem * rem;
        temp = temp / 10;
    }

    if(sum == n)
        printf("Armstrong Number");
    else
        printf("Not Armstrong Number");
}

void perfect(int n)
{
    int i, sum = 0;

    for(i = 1; i < n; i++)
    {
        if(n % i == 0)
            sum = sum + i;
    }

    if(sum == n)
        printf("Perfect Number");
    else
        printf("Not Perfect Number");
}

int main()
{
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    prime(n);
    printf("\n");

    armstrong(n);
    printf("\n");

    perfect(n);

    return 0;
}