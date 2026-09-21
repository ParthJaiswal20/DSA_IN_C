#include <stdio.h>
#include <stdlib.h>
struct tree
{
    int data;
    struct tree *right;
    struct tree *left;
};

struct tree *createnode(int value)
{
    struct tree *newnode = (struct tree *)malloc(sizeof(struct tree));
    newnode->data = value;
    newnode->right = NULL;
    newnode->left = NULL;
    return newnode;
}

struct tree *insertnode(struct tree *root, int value)
{
    if (root == NULL)
    {
        return createnode(value);
    }
    else if (root->data > value)
    {
        root = insertnode(root->left, value);
    }
    else if (root->data < value)
    {
        root = insertnode(root->right, value);
    }
    return root;
}

struct tree *minvalue(struct tree *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

struct tree *maxvalue(struct tree *root)
{
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

struct tree *deletenode(struct tree *root, int value)
{
    if (root == NULL)
    {
        return NULL;
    }
    else if (root->data > value)
    {
        root->left = deletenode(root->left, value);
    }
    else if (root->data < value)
    {
        root->right = deletenode(root->right, value);
    }
    else if (root->data == value)
    {
        if (root->left == NULL && root->right == NULL)
        {
            struct tree *temp = root;
            free(temp);
        }
        else if (root->left != NULL && root->right == NULL)
        {
            struct tree *temp = root;
            root = root->left;
            free(temp);
            return root;
        }
        else if(root->left == NULL && root->right!=NULL)
        {
            struct tree* temp = root;
            root= root->right;
            free(temp);
            return root;
        }
        else if(root->left!=NULL && root->right!=NULL)
        {
            struct tree* temp = minvalue(root->right);
            root->data = temp->data;
            root->right = deletenode(root->right,temp ->data);
            return root;
        }
    }
}

struct tree* searchNode(struct tree* root ,int value)
{
   struct tree* temp = root;
   if(root -> data > value)
   {
    return searchNode(root->left,value);
   }
   else 
   if(root->data<value)
   {
    return searchNode(root->right,value);
   }
   else if(root->data == value)
   {
    return root->data;
   }
}
void inorder_traversal(struct tree* root)
{
    inorder_traversal(root->left);
    printf("%d",root->data);
    inorder_traversal(root->right);
}
int main()
{
}