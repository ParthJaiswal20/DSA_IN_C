#include<stdio.h>
int main()
{
    int a; int b; int c;
    int arr[5] = {5,2,6,3,1};
    int max; int temp;
    for(a=0;a<5;a++)
    {
        max = a;
        for(b=a+1;b<5;b++)
        {
            if(arr[max]<arr[b])
            {
                max = b;
            }
        }
            temp = arr[a];
            arr[a] = arr[max];
            arr[max] = temp;
    }
    return 0;
}