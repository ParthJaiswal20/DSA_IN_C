#include<stdio.h>

void decine(int a);

int main()
{
    int a; 
    printf("enter the number\n");
    scanf("%d",&a);

    decine(a);
    return 0;
}
void decine(int a)
{
    if(a==0)
    {
        return;
    }
    printf("%d\n",a);
    decine(a-1);
    printf("%d\n",a);
}