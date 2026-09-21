#include <stdio.h>
#include <stdlib.h>

void printdecreasing(int a);  /*u have to decalre the function which u are calling afterwards , it is because the compiler reads
// the code from top to bottom , such that when needed to call the function which is afterwards then the main function then u must 
declare them first*/

// main function
int main()
{
    int a;
    printf("enter the number\n");
    scanf("%d", &a);
    printdecreasing(a);
    return 0;   //dont ever forget to return it 
}

// calling function
void printdecreasing(int a)
{
    if (a == 0)
    {
        return;
    }
    printf("%d\n", a);
    printdecreasing(a - 1); // recurisively calling the function , with slight change in it , like decreasing the value 
}