#include <stdio.h>

int halfpower(int x, int power);
int main()
{
    int x;
    int power;
    printf("enter the number\n");
    scanf("%d", &x);
    printf("enter the power\n");
    scanf("%d", &power);

    int call = halfpower(x, power);
    printf("%d", call);
    return 0;
}
int halfpower(int x, int power)
{
    if(power == 0)  // if the power going through decreasing becomes 0 then it will cause the issue threfore 1
    { 
        return 1;
    }
    int temp = halfpower(x,power/2); 

    //just after when we are storing the power/2 and turant cheking whether it is even or odd.
    if(power%2==0) //checking the power is even or odd
    {
        return temp*temp;
    }
    else 
    //when the power becomes odd then.
    return x*temp*temp;
}