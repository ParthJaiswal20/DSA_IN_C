#include <stdio.h>
#include <stdlib.h>

// Node structure for each element in the queue
struct Node {
    int data;             // Holds the value of the node
    struct Node* next;    // Pointer to the next node
};

// Queue structure with front and rear pointers
struct Queue {
    struct Node *front, *rear;
};

// Function to create and initialize an empty queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL; // Initially, queue is empty
    return q;
}

// Function to add an element to the queue (Enqueue operation)
void enqueue(struct Queue* q, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); // Allocate memory for new node
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = value;  // Assign data
    newNode->next = NULL;   // New node is added at the end, so next is NULL

    // If queue is empty, the new node becomes both front and rear
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        printf("Enqueued: %d\n", value);
        return;
    }

    // Otherwise, add the new node at the rear and update rear
    q->rear->next = newNode;
    q->rear = newNode;
    printf("Enqueued: %d\n", value);
}

// Function to remove an element from the queue (Dequeue operation)
void dequeue(struct Queue* q) {
    if (q->front == NULL) { // If queue is empty
        printf("Queue is empty! Cannot dequeue.\n");
        return;
    }

    struct Node* temp = q->front; // Store the front node temporarily
    q->front = q->front->next; // Move front pointer to next node

    // If front becomes NULL, set rear to NULL as well (Queue becomes empty)
    if (q->front == NULL)
        q->rear = NULL;

    printf("Dequeued: %d\n", temp->data); // Print the dequeued value
    free(temp); // Free the memory of removed node
}

// Function to display all elements of the queue
void display(struct Queue* q) {
    if (q->front == NULL) { // If queue is empty
        printf("Queue is empty.\n");
        return;
    }

    struct Node* temp = q->front;
    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function to demonstrate queue operations with user input
int main() {
    struct Queue* q = createQueue(); // Create an empty queue
    int choice, value;

    while (1) {
        // Display menu for user interaction
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Enqueue operation
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(q, value);
                break;
            
            case 2: // Dequeue operation
                dequeue(q);
                break;
            
            case 3: // Display queue elements
                display(q);
                break;
            
            case 4: // Exit the program
                printf("Exiting program...\n");
                return 0;
            
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }

    return 0;
}