#include<stdio.h>

int main()
{
    int a[5]={10,20,30,40,50};
    int i, pos=3;

    for(i=pos-1;i<4;i++)
        a[i]=a[i+1];

    for(i=0;i<4;i++)
        printf("%d ",a[i]);

    return 0;
}