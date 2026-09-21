#include <stdio.h>
int top = -1;
int end = -1;
#define MAX 100
int queue[MAX];

int is_empty()
{
    if (top == -1)
    {
        return 1;
    }
    return 0;
}

int is_full()
{
    if (end == MAX - 1)
    {
        return 1;
    }
    return 0;
}

void push(int value)
{
    if (is_full())
    {
        printf("not possible");
    }
    top = 0;
    end++;
    queue[end] = value;
    printf("The pushed value is ->%d", queue[end]);
}

void pop()
{
    if (is_empty())
    {
        printf("The queue is empty");
    }
    printf("The element popping them out is -> %d", queue[top]);
    top++;
}

void display()
{
    if (is_empty())
    {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = top; i <= end; i++)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main()
{
    int choice, value;

    while (1)
    {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice! Please enter a valid option.\n");
            return 0;
        }
    }
}