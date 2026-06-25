#include<stdio.h>

int main()
{
    int a[5]={10,20,30,40,50};
    int key=30;
    int low=0, high=4, mid;

    while(low<=high)
    {
        mid=(low+high)/2;

        if(a[mid]==key)
        {
            printf("Found at index %d",mid);
            return 0;
        }

        if(key>a[mid])
            low=mid+1;
        else
            high=mid-1;
    }

    printf("Not Found");

    return 0;
}