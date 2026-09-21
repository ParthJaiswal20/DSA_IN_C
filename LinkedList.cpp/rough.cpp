//making a doubly linked list full
/* create node
inert node
delete node
print
*/
#include<stdio.h>
#include<stdlib.h>
static int size =0;

struct ll
{
    int data;
    struct ll* next;
    struct ll* prev;
};

struct ll* createnode(int value)
{
    struct ll* Newnode = (struct ll*)malloc(sizeof(struct ll));
    Newnode->data = value;
    Newnode->prev = NULL;
    Newnode->next = NULL;
    return Newnode;
}

struct ll* insertnode(struct ll* head, int position,int value)
{
    int i;
    if(head == NULL)
    {
        head = createnode(value);
        size++;
        return head;
    }
    if(position == 0)
    {
        struct ll* newnode = createnode(value);
        newnode->next = head;
        newnode->prev = NULL;
        head->prev = newnode;
        size++;
        return newnode;
    }
    struct ll* temp = head;
    for(i=0i<position-1 && temp->next!= NULL ;i++)
    {
        temp = temp->next;
    }
    struct ll* newNode = createnode(value);
    newNode->next = temp->next;
    if(temp->next != NULL)
    temp->next->prev = newNode; 
    temp->next = newNode;
    newNode->prev = temp;
    size++;
    return head;
}