#include <stdio.h>

void printt(int a)
{ // accepting the value to continue its work
    if (a == 10)
        return; // base condition
    else
    printf(a);
        printf("Hello my name is Jarvis made by Iron Man\n");
    a++;
    printt(a); // recursive calling of the function
}
int main()
{
    int a = 1; // already giving the value such as to no to have error
    printt(a); // calling of the function with passing of the value
    return 0;
}