#include <stdio.h>
#include <stdlib.h>
// Definition of a node in the linked list
struct Node 
{
    int data;          // Data part of the node
    struct Node* next; // Pointer to the next node
};
// Function to find the nth node from the end of a singly linked list
void findNthFromEnd(struct Node* head, int n) 
{
    struct Node *first = head, *second = head;//first point both of them to the head 
    // Move the first pointer 'n' steps ahead
    for (int i = 0; i < n; i++) 
    {
        // If the list has fewer than 'n' nodes, print an error and return
        if (first == NULL) {
            printf("Error: List has fewer than %d nodes\n", n);
            return;
        }
        first = first->next;
    }
    // Move both first and second pointers one step at a time
    // until the first pointer reaches the end (NULL)
    while (first != NULL) {
        first = first->next;  // Move first ahead
        second = second->next; // Move second ahead
    }
    // Now, second is pointing to the nth node from the end
    printf("The %d-th node from the end is: %d\n", n, second->data);
}
// Function to insert a new node at the beginning of the linked list
struct Node* insert(struct Node* head, int data) 
{
    // Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    // Assign data to the new node
    newNode->data = data;
    // New node points to the current head of the list
    newNode->next = head;   
    // New node becomes the new head
    return newNode;
}
// Function to print the linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n"); // Indicate the end of the list
}
int main() 
{
    struct Node* head = NULL; // Initialize an empty linked list
    // Creating a linked list: 1 -> 2 -> 3 -> 4 -> 5 -> NULL
    head = insert(head, 5);
    head = insert(head, 4);
    head = insert(head, 3);
    head = insert(head, 2);
    head = insert(head, 1);
    // Print the current linked list
    printList(head);
    int n = 2; // Find the 2nd node from the end
    findNthFromEnd(head, n); // Call the function
    return 0; // Indicate successful execution
}