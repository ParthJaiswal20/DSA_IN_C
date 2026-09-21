#include <stdio.h>
#include <stdlib.h>
// Global variable to track the size of the linked list
static int size = 0;

// Definition of the Node structure
struct Node // self made datatype means kis prakar ka dabba hai . to make the node/dabba to store the val at left and address(*next) in the right
{
    int val;
    struct Node *next; // as this is the pointer and pointer needs some data type to store, and as we need to store this address in the node/dabba thats why struct Node*
};

//-------------------------------------------------------------------------------------------------------

// Function to create a new node
// createNew(datatype) is a type of function whihc is used to make a new datatype
struct Node *createNewNode(int data) // to make a new node of data type like struct Node.
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node)); // dynamic memory allocation to the new node i have maked
    if (!newNode)                                                      // means the memory is not alloted
    {
        printf("Memory Allocation failed.\n");
        return NULL;
    }
    newNode->val = data;  // new node ke val mein data store karo
    newNode->next = NULL; // new node/dabba ke next mein null store karo , aur ye vo next hai jo address store karata hi apne bad wale ka
    return newNode;
}
// create node we use to make a new node again and again , in simple har bar ak naya dabba bana hai isliye hame createNewNode function ka use kar rahe hai

//------------------------------------------------------------------------------------------------------------------

// Function to insert a node at a specified position
// for insertion u need element , poosition to inset , our head , bcz AT THEN END U HAVE TO CHECK ALSO WHETHER THE HEAD IS NOT NULL AND TO RETURN THE HEAD ALSO
struct Node *insertNode(int ele, int position, struct Node *head)
{
    // Simple case: list is empty, just create the first node
    if (head == NULL)
    {
        head = createNewNode(ele);
        if (head != NULL)
        {
            size = 1;
        }
        return head;
    }


    // Edge case: invalid position
    if (position < 0 || position > size)
    {
        printf("Invalid Position entered, try again.\n");
        return head;
    }


    // Special case: insert at the head
    if (position == 0)
    {
        struct Node *newHead = createNewNode(ele);
        if (newHead == NULL)
        {
            return head;
        }
        newHead->next = head;
        size += 1;
        return newHead;
    }

    // Traverse to the node before the insert position
    struct Node *current = head;
    for (int i = 0; i < position - 1; i++)
    {
        current = current->next;
    }
    // Insert the new node
    struct Node *newNode = createNewNode(ele);
    if (newNode == NULL)
    {
        return head;
    }
    newNode->next = current->next;
    current->next = newNode;
    size += 1;  
    return head;
}

//----------------------------------------------------------------------------------------------------------------

// Function to delete a node at a specified position
struct Node *deleteNode(int position, struct Node *head) // FULL FUNCTION TO DELETE
{
    // USING IF CASES TO CHECK WHICH TYPE OF DELETION TO PERFORM
    //  Edge case: if the list is empty
    if (head == NULL)
    {
        printf("List is empty\n");
        return NULL;
    }

    // Edge case: invalid position
    if (position < 0 || position > size - 1)
    {
        printf("Invalid position.\n");
        return head;
    }

    // Special case: deleting the head node
    if (position == 0)
    {
        struct Node *temp = head; // making temo variable
        head = head->next;
        free(temp);
        size -= 1;
        return head;
    }

    // Traverse to the node before the one to be deleted
    struct Node *current = head;
    for (int i = 0; i < position - 1; i++)
    {
        current = current->next;
    }

    // Remove the node from the list
    struct Node *temp = current->next;
    current->next = temp->next;
    free(temp);
    size -= 1;
    return head;
}
//--------------------------------------------------------------------------------------------------------
// Function to print the linked list
void printList(struct Node *head)
{
    struct Node *current = head; // making a varaible of our personal data type and storing the head in it
    printf("Linked List: ");
    if (current == NULL)
    {
        printf("Empty");
    }
    while (current != NULL)
    {
        printf("%d -> ", current->val); // taking the value in the current
        current = current->next;
    }
    printf("NULL\n");
}

//-----------------------------------------------------------------------------------------------------------------------

// Function to free all memory before exiting
void freeList(struct Node *head)
{
    struct Node *current = head;
    struct Node *next;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
}

// Main function with switch case menu to perform different operation on the basis of the user need
int main()
{
    struct Node *head = NULL;
    int choice, ele, pos;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Insert Element\n");
        printf("2. Delete Element\n");
        printf("3. Print List\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            if (head == NULL)
            {
                // If list is empty, directly insert the element
                printf("Enter value to insert: ");
                scanf("%d", &ele);
                head = createNewNode(ele);
                if (head != NULL)
                {
                    size = 1;
                    printf("Element %d inserted as first node\n", ele);
                }
            }
            else
            {
                printf("Enter value to insert: ");
                scanf("%d", &ele);
                printf("Enter position to insert at (0 for beginning to %d): ", size);
                scanf("%d", &pos);
                head = insertNode(ele, pos, head);
            }
            break;

        case 2:
            if (head == NULL)
            {
                printf("List is empty, nothing to delete\n");
            }
            else if (head->next == NULL)
            {
                // If only one element exists, directly delete it
                free(head);
                head = NULL;
                size = 0;
                printf("Single element deleted, list is now empty\n");
            }
            else
            {
                printf("Enter position to delete (0 for first element to %d): ", size);
                scanf("%d", &pos);
                head = deleteNode(pos, head);
            }
            break;

        case 3:
            printList(head);
            printf("List size: %d\n", size);
            break;

        case 4:
            printf("Exiting...\n");
            freeList(head);
            return 0;

        default:
            printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}