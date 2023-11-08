#include<stdio.h>
int main()
{
     int n,temp;
     int found=0;
     int value;
    printf("enter the number:");
    scanf("%d",&n);
    int arr[n];
    printf("enter array elements :\t");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("enter elemant for search:");
    scanf("%d",&temp);
    for(int i=0;i<n;i++)
    {
        if(temp==arr[i])
        {
            found=1;
            value=i;
            
        }

    }
    if(found==1){
        printf("elemet found at position \t %d",value);
    }
    else{
        printf("elemet not found");
    }

}