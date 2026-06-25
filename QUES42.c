#include<stdio.h>

int main()
{
    int a[3]={1,2,3};
    int b[3]={4,5,6};
    int i;

    for(i=0;i<3;i++)
        printf("%d ",a[i]);

    for(i=0;i<3;i++)
        printf("%d ",b[i]);

    return 0;
}