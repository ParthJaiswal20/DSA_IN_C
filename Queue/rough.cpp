#include<stdio.h>
#include<stdlib.h>

struct queue
{
    int data;
    struct queue* right;
    struct queue* left;
};

struct queue* createnode(int value)
{
    struct queue* Newnode = (struct queue*)malloc(sizeof(struct queue));
    Newnode->data= value;
    Newnode->left= NULL;
    Newnode->right = NULL;
    return Newnode;
}

struct queue* enqueue(int value)
{
    if(rear==NULL)
    {
        return createnode(value);
    }
}