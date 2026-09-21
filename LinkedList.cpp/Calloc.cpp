#include<iostream>
#include <stdlib.h>
int main()
{
    //use of calloc
    int *ptr; int size;
    ptr = (int*)calloc(3,sizeof(int)); //during this time i am already telling the memory i need .
    int i;
    for(i=0;i<3;i++) 
    {
        printf("%d\n",ptr[i]);
    }
    printf("\nenter the size u want");
    scanf("%d",&size);
    int *Ptr;
    Ptr = (int*)calloc(size,sizeof(int)); //during this time i am already telling the memory i need .
    int a;
    for(a=0;a<size;a++) 
    {
        printf("enter the value when second time when user tells the size \n");
        scanf("%d",&Ptr[a]);
    }

    for(a=0;a<size;a++)
    {
        printf("when user entered the size , means size during runtime%d\n",Ptr[a]);
    }
    return 0;
}