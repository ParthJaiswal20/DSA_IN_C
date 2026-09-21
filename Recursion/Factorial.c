#include <stdio.h>
int factorial(int num);
int main()
{
    int num;
    printf("enter the number\n");
    scanf("%d", &num);
    int call = factorial(num);  // this iss calling the funtion , made a seperate variable
// such that it is easy to print the value recieving from it in the next line 
    printf("%d", call);
    return 0;
}

int factorial(int num)  //using the int function bcz i have to return the values
{
    int a = 1;
    if (num == 1)
    {
        return 1;
    }
    int b = factorial(num - 1);
    a = num * b; 
    return a; // returning back the value , calculated.
}