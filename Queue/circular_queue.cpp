#include <stdio.h>

// Global variables to keep track of the front and rear of the queue
int top = -1; // Front of the queue
int end = -1; // Rear of the queue

#define MAX 100 // Maximum size of the queue
int queue[MAX]; // Array to store queue elements

// Function to check if the queue is empty
int is_empty()
{
    if (top == -1)
    {
        return 1; // Queue is empty
    }
    return 0; // Queue is not empty
}

// Function to check if the queue is full (Circular Queue Condition)
int is_full()
{
    if ((end + 1) % MAX == top) // If next position of end is equal to top, queue is full
    {
        return 1;
    }
    return 0;
}

// Function to insert an element into the queue
void push(int value)
{
    if (is_full()) // Check if queue is full
    {
        printf("not possible"); // Display error message
        return;
    }
    if (top == -1) // If queue was empty, initialize front to 0
    {
        top = 0;
    }
    end = (end + 1) % MAX; // Increment rear circularly
    queue[end] = value; // Insert value
    printf("The pushed value is ->%d", queue[end]); // Display pushed value
}

// Function to remove an element from the queue
void pop()
{
    printf("The element popping them out is -> %d", queue[top]); // Display the element being removed
    if (is_empty()) // Check if queue is empty
    {
        printf("The queue is empty");
        return;
    }
    if (top == end) // If there was only one element, reset queue
    {
        top = -1;
        end = -1;
    }
    else 
    {
        top = (top + 1) % MAX; // Move front forward in a circular manner
    }
}

// Function to display all elements in the queue
void display()
{
    if (is_empty()) // Check if queue is empty
    {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue elements: ");
    int i = top;
    while (1)
    {
        printf("%d ", queue[i]); // Print current element
        if (i == end) // Stop when we reach the last element
            break;
        i = (i + 1) % MAX; // Move forward circularly
    }
    printf("\n");
}

// Main function to provide menu-based interaction
int main()
{
    int choice, value;

    while (1)
    {
        // Display menu options
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice); // Read user choice

        switch (choice)
        {
        case 1:
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(value); // Call push function
            break;
        case 2:
            pop(); // Call pop function
            break;
        case 3:
            display(); // Call display function
            break;
        case 4:
            printf("Exiting...\n");
            return 0; // Exit the program
        default:
            printf("Invalid choice! Please enter a valid option.\n");
            return 0;
        }
    }
}
