// Stack using Linked List
#include<stdio.h>
#include<stdlib.h>

// Structure to represent a stack node
struct stack
{
    int data;               // Data stored in the node
    struct stack* next;     // Pointer to the next node
};

// Function to push an element onto the stack
struct stack* push(int ele, struct stack* top)
{
    struct stack* newnode = (struct stack*)malloc(sizeof(struct stack)); // Allocate memory for new node
    newnode->data = ele;   // Assign the value to the new node
    newnode->next = top;   // Point new node to the current top
    return newnode;        // Return the new top of the stack
}

// Function to pop an element from the stack
struct stack* pop(struct stack* top)
{
    if (top == NULL) // Check if the stack is empty
    {
        printf("The stack is empty\n");
        return NULL;
    }
    
    int popped = top->data; // Store the value before deleting
    struct stack* temp = top; // Store the current top node
    top = top->next;          // Move top to the next node
    free(temp);               // Free memory of the popped node to avoid memory leak

    printf("The popped value is %d\n", popped);
    return top; // Return the new top after popping
}

// Function to print the stack elements
void print(struct stack* top)
{
    struct stack* traverser = top; // Start from the top of the stack
    while (traverser != NULL)
    {
        printf("%d -> ", traverser->data); // Print the data
        traverser = traverser->next;       // Move to the next node
    }
    printf("NULL\n"); // Indicate the end of the stack
}

// Function to display the topmost element (peek)
void peek(struct stack* top)
{
    if (top == NULL) // Check if stack is empty
    {
        printf("Stack is empty!\n");
        return;
    }
    printf("The topmost element value is -> %d\n", top->data);
}

// Main function to handle stack operations
int main()
{
    struct stack* top = NULL;  // Initialize stack as empty

    int choice, val;

    while (1) // Infinite loop to display menu until user exits
    {
        // Display menu options
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
            case 1: // Push operation
                printf("Enter value to push: ");
                scanf("%d", &val);
                top = push(val, top); // Update top after push
                break;

            case 2: // Pop operation
                top = pop(top); // Update top after pop
                break;

            case 3: // Peek operation
                peek(top);  
                break;

            case 4: // Print stack elements
                print(top); 
                break;

            case 5: // Exit program
                printf("Exiting...\n");
                return 0;

            default: // Handle invalid choices
                printf("Invalid choice, try again.\n");
        }
    }
    return 0;
}
