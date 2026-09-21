#include <stdio.h>
#include <conio.h>
#define MAX 100
int top = -1;
int stack[MAX];

int is_empty()
{
    if (top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int is_full()
{
    if (top == MAX-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(int value)
{
    if(is_full())
    {
        printf("no space");
    }
    else 
    {
    top++;
    stack[top]=value;
    printf("the pushed vlaue is-> %d",stack[top]);
    }
}

void pop()
{
    int a;
    if(is_empty())
    {
        printf("stack underflow\n");
    }
    else
    {
    a = stack[top];
    top--;
    printf("the removed value is -> %d",a);
    }
}

int main()
{
    push(1);
    push(2);
    push(3);
    pop();
    push(4);
    pop();
    push(5);
    return 0;
}