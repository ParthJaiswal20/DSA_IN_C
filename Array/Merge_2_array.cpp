#include<stdio.h>
#define MAX 5
int arr[MAX];
int aar[MAX];
int merge[MAX*2]; //taking the double of the size as we storing the two arrays data in one array.
int main()
{
    int a; 
    printf("enter the elements in the array\n");
    for(a=0;a<MAX;a++)
    {
        scanf("%d",&arr[a]);
    }

    printf("enter the elements in the array\n");
    for(a=0;a<MAX;a++)
    {
        scanf("%d",&aar[a]);
    }

    for(a=0;a<MAX;a++)
    {
        merge[a] = arr[a];
    }
    for(a = 0; a < MAX; a++) 
    {
        merge[a + MAX] = aar[a];  // Correct index mapping
    }

    //printng the merged array
    for(a=0;a<MAX*2;a++)
    {
        printf("%d",merge[a]);
    }
    return 0;
}