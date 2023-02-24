//input - {-2, -3, 4, -1, -2, 1, 5, -3}
//maximum contigous sum 7

#include <stdio.h>
int main()
{
    //int arr[8]={-2,-3,4,-1,-2,1,5,-3};
    int arr[5]={-5,-2,-3,-4,-1};
    int n=sizeof(arr)/sizeof(arr[0]);
    printf("%d\n",sizeof(arr));
    int max_sum=0,sum_temp=0,temp;
    int i,j,k;
    for(int t=0;t<(sizeof(arr)/sizeof(arr[0]));t++)
    printf("%d\t",arr[t]);

    for(int t=0;t<(sizeof(arr)/sizeof(arr[0]));t++) 
    {
        temp=arr[t];
        if(temp<max_sum)
        max_sum=temp;
    }
    for(i=0;i<n;i++)
    {
        for(j=i;j<n;j++)
        {
            for(k=i;k<=j;k++)
            {
                sum_temp=sum_temp+arr[k];
            }
            if(sum_temp>max_sum)
            max_sum=sum_temp;

            sum_temp=0;
        }
    }
    printf("the maximum contiguous sum is %d",max_sum);
return 0;
}