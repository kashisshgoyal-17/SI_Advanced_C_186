#include<stdio.h>

int main()
{
    int a[2][2];
    int i,j,flag=1;

    printf("Enter matrix:\n");
    for(i=0;i<2;i++)
        for(j=0;j<2;j++)
            scanf("%d",&a[i][j]);

    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            if(a[i][j] != a[j][i])
            {
                flag=0;
                break;
            }
        }
    }

    if(flag==1)
        printf("Symmetric Matrix");
    else
        printf("Not Symmetric Matrix");

    return 0;
}