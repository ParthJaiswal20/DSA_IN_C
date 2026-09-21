#include<stdio.h>
#include<stdlib.h>

//decalring the recursive calling function
void increasing(int a);

//main function
int main()
{
    int input;
    printf("enter the number\n");
    scanf("%d",&input);

    increasing(input);
    return 0;
}

// recursive function delcration 
void increasing(int input)
{ 
    // base condition
    if(input==0)
    {
        return;
    }
    increasing(input-1);
    printf("%d\n",input);
}