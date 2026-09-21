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

//PREORDER TRAVERSING 
void preorder(struct node *root, vector<int> &arr)
// root-> the current node of the tree
// arr is the array to store the values while traversing
{
    if (root == NULL)
    {
        return;
    }
    arr.push_back(root->data);
    // this is the left side
    preorder(root->left, arr);
    // below one is for the root one, direct push when it comes to the root
    // directly pushing the root in the arr as after the left we have root
    /* so when the left side traversing is done completely, when it moves to the root side,
       then it will directly save it in the arr by pushing it in the arr.

       Simply, you can understand it like when the above left side traversing is done with the help of the root,
       we are directly assigning the root's data now and forcefully pushing it into the stack.
    */

    // this is for right side
    preorder(root->right, arr);
}


vector<int> preOrder(struct node *root)
{
    // Create an empty vector to store preorder traversal values
    vector<int> arr;
    // Call the preorder traversal function
    preorder(root, arr);
    // Return the resulting vector containing preorder traversal values
    return arr;
}


int main()
{
    // Creating a sample binary tree
    //mannually creating the tree by again and again calling the NODE making MACHINE the CREATE NODE function.
    struct node *root = createnode(1);
    root->left = createnode(2);
    root->right = createnode(3);
    root->left->left = createnode(4);
    root->left->right = createnode(5);

    // Getting preorder traversal
    vector<int> result = preOrder(root);

    // Displaying the preorder traversal result
    printf("Preorder Traversal: ");
    for (int i = 0; i < result.size(); i++)
    {
        printf("%d ", result[i]);
    }
    printf("\n");

    return 0;
}
