#include <stdio.h>

int main()
{
    int a[5], *p;
    int i, key, found = 0;

    p = a;

    printf("Enter 5 elements:\n");

    for(i = 0; i < 5; i++)
        scanf("%d", p + i);

    printf("Enter element to search: ");
    scanf("%d", &key);

    for(i = 0; i < 5; i++)
    {
        if(*(p + i) == key)
        {
            found = 1;
            break;
        }
    }

    if(found)
        printf("Element found at index %d", i);
    else
        printf("Element not found");

    return 0;
}