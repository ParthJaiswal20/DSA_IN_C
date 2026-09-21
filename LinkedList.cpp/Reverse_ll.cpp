#include <stdio.h>
#include <stdlib.h>

// Static variable to track the size of the linked list
static int size = 0;

// Definition of a node in the linked list
struct node
{
    int data;
    struct node *nextptr;
};

// Function to create a new node
struct node *createnode(int ele)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node)); // Allocate memory
    newnode->data = ele;                                               // Store the value
    newnode->nextptr = NULL;                                           // Initially, the next pointer is NULL
    return newnode;                                                    // Return the newly created node
}

// Function to insert a node at a specific position
struct node *insertnode(int position, int value, struct node *head)
{
    if (position < 0 || position > size) // Handle invalid position
    {
        printf("Invalid position! The list size is %d.\n", size);
        return head;
    }

    struct node *newnode = createnode(value); // Create a new node

    if (position == 0) // If inserting at the beginning
    {
        newnode->nextptr = head; // Point new node to the old head
        size++;
        return newnode; // New node becomes the head
    }

    struct node *traverse = head;          // Store head
    for (int i = 0; i < position - 1; i++) // Move to the (position-1) node
    {
        traverse = traverse->nextptr;
    }

    newnode->nextptr = traverse->nextptr; // Adjust pointers to insert
    traverse->nextptr = newnode;
    size++;

    return head;
}


// Function to delete a node from a specific position
struct node *deletenode(int position, struct node *head)
{
    if (head == NULL)
    {
        printf("List is empty, nothing to delete.\n");
        return head;
    }

    if (position < 0 || position >= size)
    {
        printf("Invalid position! The list size is %d.\n", size);
        return head;
    }

    struct node *temp = head; //as we are deleting the head such as not to loose the head, isloye securing it 

    if (position == 0) // Deleting the first node
    {
        head = head->nextptr;  //just moved head to heads next element
        free(temp);
        size--;
        return head;
    }

    struct node *current = NULL; //
    for (int i = 0; i < position; i++) // Move to (position-1) node
    {
        current = temp; //to have the recent node which we want to delete 
    //as we are travelling till position -1 as i < position
        temp = temp->nextptr;  //moving to the next node 
    //as like u were doing in inserting at a particular postion
//same over here aslo just stroing the temp value in the current
//as such that when we moved to next postion we lost the postn we want to remove
    }
    current->nextptr = temp->nextptr; // Skip the node to be deleted
//means its like 1 = 2 and 2=3 , so 1=3
    free(temp);
    size--;

    return head;
}


// Function to print the linked list
void printll(struct node *head)
{
    if (head == NULL)
    {
        printf("The linked list is empty.\n");
        return;
    }

    struct node *temp = head;
    while (temp != NULL) // Traverse and print
    {
        printf("%d->", temp->data);
        temp = temp->nextptr;
    }
    printf("NULL\n");
}

//----------------------------------------------------------------------------------
// Function to reverse the linked list permanently
struct node *reverseList(struct node *head)
{
    if (head == NULL)
    {
        printf("The linked list is empty.\n");
        return NULL;
    }

    struct node *prev = NULL, *curr = head, *next = NULL;

    /*
        Reversing the list step by step:
        1. Save the next node (so we don't lose it)
        2. Make the current node point to the previous node
        3. Move previous and current one step forward
    */
    while (curr != NULL) //jab tak mera current null na ho
//bcz agar null  hua to mera next bhi to null ho jayega 
    {
        next = curr->nextptr; // Store next node
        curr->nextptr = prev; // Reverse pointer direction
        prev = curr;          // Move prev to current
        curr = next;          // Move current to next
    }

    // 'prev' now points to the new head
    return prev;
}
//---------------------------------------------------------------------------------------------------------------

// **Main function** - Driver code to run the program
int main()
{
    struct node *head = NULL; // Initialize head pointer
    int choice, val, pos;

    while (1)
    {
        // Display menu options
        printf("\nMenu:\n");
        printf("1. Insert Node\n");
        printf("2. Delete Node\n");
        printf("3. Print List\n");
        printf("4. Reverse Linked List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Perform operations based on user input
        switch (choice)
        {
        case 1:
            printf("Enter position to insert (0 to %d): ", size);
            scanf("%d", &pos);
            printf("Enter value to insert: ");
            scanf("%d", &val);
            head = insertnode(pos, val, head);
            break;

        case 2:
            if (size == 0)
            {
                printf("List is empty, nothing to delete.\n");
                break;
            }
            printf("Enter position to delete (0 to %d): ", size - 1);
            scanf("%d", &pos);
            head = deletenode(pos, head);
            break;

        case 3:
            printll(head); // Print the original linked list
            break;

        case 4:
            head = reverseList(head); // Reverse the list permanently
            printf("Linked list reversed successfully!\n");
            break;

        case 5:
            printf("Exiting...\n");
            return 0; // Exit the program

        default:
            printf("Invalid choice, try again.\n");
        }
    }
    return 0;
}