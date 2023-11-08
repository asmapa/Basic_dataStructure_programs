//BUBBLE SORTING

#include<stdio.h>
int main()
{
    int n,temp;
    printf("enter the number:");
    scanf("%d",&n);
    int arr[n];
    printf("enter array elements :\t");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            printf("%d", *(arr+j));
            printf("%d", *(arr+j+1));
            if( *(arr+j) > *(arr+j+1))
            {
                temp = *(arr+j);
                printf("temp=%d",temp);
                *(arr+j) = *(arr+j+1);
                *(arr+j+1)= temp;
            }
        }
    }
    printf("sorted array are:");
      for(int i=0;i<n;i++)
      {
        printf("%d",arr[i]);
    }
}
