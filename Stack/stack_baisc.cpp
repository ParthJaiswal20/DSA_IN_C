#include<stdio.h>
int top =-1;
#define MAX 100
int stack[MAX];

int is_empty()
{
    if(top==-1)
    {
        return 1;
    }
    return 0;
}

int is_full()
{
    if(top==MAX-1)
    {
        return 1;
    }
    return 0;
}

void push(int value)
{
    top++;
    stack[top]=value;
    printf("The vlaue pushed is ->%d\n",stack[top]);
}

void pop()
{
    int popped;
    popped = stack[top];
    top--;
    printf("The popped element is-> %d\n",popped);
}

void print_stack() {
    if (is_empty()) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements (top to bottom): ");
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main()
{
    int val; int a;
    for(a=0;a<3;a++)
    {
    printf("Enter the value to push\n");
    scanf("%d",&val);
    push(val);
    }
    print_stack(); 
    pop();
    print_stack(); 
    return 0;
}