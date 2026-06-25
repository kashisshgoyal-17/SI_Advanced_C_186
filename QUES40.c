#include<stdio.h>

int main()
{
    int a[10]={10,20,30,40,50};
    int i, pos=3, num=25;

    for(i=5;i>=pos;i--)
        a[i]=a[i-1];

    a[pos-1]=num;

    for(i=0;i<6;i++)
        printf("%d ",a[i]);

    return 0;
}