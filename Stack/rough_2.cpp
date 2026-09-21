#include<stdio.h>
int queue[100];
int end, front =-1;

int is_empty()
{
    if(front==-1)
    {
        return 1;
    }
    return 0;
}

int is_full()
{
    if(end==99)
    {
        return 1;
    }
    return 0;
}

void push(int value)
{
    if(is_full())
    {
        printf("the queue is full\n");
    }
    front =0;
    end++;
    queue[end]=value;
    printf("the value pushed is %d",queue[end]);
}

int pop()
{
    int popped;
    if(is_empty())
    {
        printf("no element");
    }
    popped = queue[front];
    front++;
    printf("the popped element is-> %d\n",popped);
    return 0;
}

int main()
{
    push(1);
    pop();
    push(2);
    push(3);
    return 0;
}