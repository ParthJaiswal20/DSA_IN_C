#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;

//as u have to make a node thats why u have to make your own personalised data type
struct node
{
    int data;
    struct node *right;
    struct node *left;
};
//function to create the new nodes again and again when needed
struct node *createnode(int val)
{
    struct node *Newnode = (struct node *)malloc(sizeof(struct node));
    Newnode->data = val;
    Newnode->left = NULL;
    Newnode->right = NULL;
    return Newnode;
}
//--------------------------------------------------------------------
//INORDER TRAVERSING 
void inorder(struct node *root, vector<int> &arr)
// root-> the current node of the tree
// arr is the array to store the values while traversing
{
    if (root == NULL)
    {
        return;
    }
    // this is the left side
    inorder(root->left, arr);
    // below one is for the root one, direct push when it comes to the root
    arr.push_back(root->data); // directly pushing the root in the arr as after the left we have root
    /* so when the left side traversing is done completely, when it moves to the root side,
       then it will directly save it in the arr by pushing it in the arr.

       Simply, you can understand it like when the above left side traversing is done with the help of the root,
       we are directly assigning the root's data now and forcefully pushing it into the stack.
    */

    // this is for right side
    inorder(root->right, arr);
}

//-----------------------------------------------------------------------------------
//This function collects and returns the tree’s values in sorted order (Left → Root → Right).
vector<int> inOrder(struct node *root)
{
    vector<int> arr;// Create an empty vector to store inorder traversal values
    inorder(root, arr);// Call the inorder traversal function
    return arr;// Return the resulting vector containing inorder traversal values
}


int main()
{
    // Creating a sample binary tree
    struct node *root = createnode(1);
    root->left = createnode(2);
    root->right = createnode(3);
    root->left->left = createnode(4);
    root->left->right = createnode(5);

    // Getting inorder traversal
    vector<int> result = inOrder(root);

    // Displaying the inorder traversal result
    printf("Inorder Traversal: ");
    for (int i = 0; i < result.size(); i++)
    {
        printf("%d ", result[i]);
    }
    printf("\n");

    return 0;
}
