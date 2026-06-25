#include<stdio.h>

int main()
{
    int a[5]={10,20,30,40,50};
    int i,key=30;

    for(i=0;i<5;i++)
    {
        if(a[i]==key)
        {
            printf("Found at index %d",i);
            break;
        }
    }

    return 0;
}