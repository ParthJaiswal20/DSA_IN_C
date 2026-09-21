#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a; int b; 
    int arr[5] = {2,4,1,5,3};
    int size = 5;
    int min;
    for(a=0;a<size-1;a++)
    {
        min = a;
        for(b=a+1;b<5;b++)
        {
            if(arr[b]<arr[min])
            {
                min = b;
            }
        }
        int temp = arr[a];
        arr[a] = arr[min];
        arr[min] = temp;
    }
    for(a=0;a<5;a++)
    {
        printf("%d",arr[a]);
    }
    return 0;
}