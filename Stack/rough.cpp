//stack using ll
#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int data;
    struct stack* next;
};

struct stack* push(int ele,struct stack* top)
{
    struct stack* newnode =(struct stack*)malloc(sizeof(struct stack));
    newnode->data = ele;
    newnode->next = top;
    return newnode;
}

struct stack* pop(struct stack* top)
{
    if (top == NULL)
    {
        printf("The stack is empty\n");
        return NULL;
    }
    int popped = top->data;  // Store the value before deleting
    struct stack* temp = top; // Store the current top
    top = top->next;          // Move top to the next node
    free(temp);               // Free old top node (avoiding memory leak)

    printf("The popped value is %d\n", popped);
    return top; // Return the new top
}
void print(struct stack* top)
{
    struct stack* traverser= top;
    while(traverser!=NULL)
    {
        printf("%d->",traverser->data);
        traverser= traverser->next;
    }
}

void peek(struct stack* top)
{
    printf("the top most element value is ->%d",top->data);
}
int main()
{
    struct stack* top = NULL;  // ➜ struct node* top should be struct stack* top

    int choice, val;

    while (1) 
    {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Print\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &val);
                top = push(val, top); // ➜ push function must return the updated top
                break;

            case 2:
                top = pop(top); // ➜ pop must return the new top after popping
                break;

            case 3:
                if (top != NULL)
                    peek(top); 
                else
                    printf("Stack is empty!\n");
                break;

            case 4:
                print(top); 
                printf("NULL\n"); // ➜ To indicate the end of the stack
                break;

            case 5:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice, try again.\n");
        }
    }
    return 0;
}