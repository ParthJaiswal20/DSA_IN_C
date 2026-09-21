#include <stdio.h>
int power(int x, int n);
int main()
{
    int x;
    int n;
    printf("enter the number\n");
    scanf("%d", &x);
    printf("enter the power\n");
    scanf("%d", &n);

    int call = power(x, n);
    printf("%d", call);
    return 0;
}

int power(int x, int n)
{
    int cal = 1;
    if (n == 0)
    {
        return 1;
    }
    int call = power(x, n - 1);
    cal = x * call;
    return cal;
}