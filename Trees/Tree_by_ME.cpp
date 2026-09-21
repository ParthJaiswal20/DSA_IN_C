#include <iostream>
using namespace std;
#include <stdio.h>

// creating your own personal data type
struct tree
{
    // a tree has a data in it like a node
    int data;
    // a tree has two sides rigth side and left side
    struct tree *right;
    struct tree *left;
};

// creating a function / machine to make nodes when required of same type
struct tree *createnode(int value)
{
    struct tree *Newnode = (struct tree *)malloc(sizeof(struct tree));
    Newnode->data = value;
    Newnode->left = NULL;
    Newnode->right = NULL;
    return Newnode;
}

//-----------------------------------------------------------------
// function to insert the node in the tree
// asked root and the value
struct tree *insertTree(struct tree *root, int value)
{
    if (root == NULL) // checking ki kahi mere pass tree hi to nahi
    {
        return createnode(value);
    }
    // checking condition to understand where to move , either in the right or in the left
    else if (root->data < value)
    {
        root->right = insertTree(root->right, value);
    }
    else if (root->data > value)
    {
        root->left = insertTree(root->left, value);
    }
    return root; // cannot leave the root , bcz without this u will loose the data.
}

//--------------------------------------------------------------------------------------------------
// function to search a data type in the tree
struct tree *searchNode(struct tree *root, int value)
{
    struct tree *temp = root;
    if (root == NULL)
    {
        printf("no tree present");
        return NULL;
    }
    if (root->data < value)
    {
        return searchNode(root->right, value);
        //  root -> right = searchNode(root->right,value);  ---> not use it BCZ it used only in INSERTION and DELETION ,
        // but here u dont have to do anything u have to only traverse . thats why
    }
    else if (root->data > value)
    {
        return searchNode(root->left, value);
        // root->left = searchNode(root->left,value); ->>> not to use this as this is done when u have to do modifications in the BST
        // but here u dont have to do the modifications thats when just call the function it self and return it when done
    }
    else if (root->data == value)
    {
        printf("found the element\n");
        return root;
    }
    return root;
}
//-----------------------------------------------------------------------
// function to find the Minimum value in the tree
// as the minimum value will always be in the left side , therefore only need to check the right side
// as the tree follows the rule of  (LEFT(nodes value)<ROOT(nodes value)<RIGHT(node values))
struct tree *minValueNode(struct tree *root){
//as in the delete function we have passed the root->right ,

/*In deletion, we EITHER
✅ find the min value from the right subtree (by going left),
OR
✅ find the max value from the left subtree (by going right)
*/
    while (root->left != NULL) // we will gp to left upto till we find the root is null.
    {
        root = root->left;
    }
    return root; // left most node found return it
    /*50
    /  \
   30   70
  /  \  /  \
 20  40 60  80
    ✅ Calling minValueNode(root) will return 20 (smallest value in the entire tree).
✅ Calling minValueNode(root->right) will return 60 (smallest in the right subtree).*/
}
//--------------------------------------------------------------------------------------------------------------------
// Function to delete the node in the tree
//  needed the head and the value, bcz without head u can not traverse in the tree and without the value u can not identify which value to delete
struct tree *deletenode(struct tree *root, int value)
{
    if (root == NULL) // checking ki kahi mere pass tree hi to nahi
    {
        printf("no tree to go check and delete\n");
        return NULL;
    }
    // checking condtions to knwo whether to traverse in the right side of the tree or in the left side of the tree.
    //  this below to function are only to tell the direction to which we have to travell
    /*here ->*/ else if (root->data < value)
    {
        root->right = deletenode(root->right, value);
    }
    else if (root->data > value)
    {
        root->left = deletenode(root->left, value);
/*to here ->*/ }

// this is the if else when above one have made u traversed till in the right or in the left side where the element can be present
else if (root->data == value) // condition when u have founded the element while traversing in the right subtree or in the left subtree
{
    // case 1:- no children
    if (root->left == NULL && root->right == NULL)
    {
        struct tree *temp = root;
        free(temp);
        return NULL;
    }

    // case 2:- if one children either in right or in the left
    if (root->left == NULL && root->right != NULL)
    {
        struct tree *temp = root;
        root = root->right;
        free(temp);
        return root;
    }

    else if (root->left != NULL && root->right == NULL)
    {
        struct tree *temp = root;
        root = root->left;
        free(temp);
        return root;
    }

    // case 3:- if have both children ,in right and in the left.
    else
    {

        // Find the minimum node in the right subtree
        struct tree *temp = minValueNode(root->right);

        // Copy its value to the current node
        //tmep ka data jo min value fun ne khoj ke diya hai vo copy ho gaya hai root->data, jisko delete karna tha
        root->data = temp->data;
        
        // Delete the duplicate node from the right subtree
        root->right = deletenode(root->right, temp->data);
        return root;
    }
}
}

//--------------------------------------------------------------------------
// inorder traversal function
void inorder_traversal(struct tree *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder_traversal(root->left);
    printf("%d", root->data);
    inorder_traversal(root->right);
}
//--------------------------------------------------
// postorder traversal function
void postorder_traversal(struct tree *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder_traversal(root->left);
    postorder_traversal(root->right);
    printf("%d", root->data);
}

//--------------------------------------------------
// preorder traversal function
void preorder_traversal(struct tree *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d", root->data);
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}

//-------------------------------------------
int main()
{
    struct tree *root = NULL;
    int choice, value;

    while (1)
    {
        printf("\nBinary Search Tree Operations:");
        printf("\n1. Insert\n2. Search\n3. Delete\n4. Inorder Traversal\n5. Preorder Traversal\n6. Postorder Traversal\n7. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            root = insertTree(root, value);
            break;
        case 2:
            printf("Enter value to search: ");
            scanf("%d", &value);
            searchNode(root, value);
            break;
        case 3:
            printf("Enter value to delete: ");
            scanf("%d", &value);
            root = deletenode(root, value);
            break;
        case 4:
            printf("Inorder Traversal: ");
            inorder_traversal(root);
            printf("\n");
            break;
        case 5:
            printf("Preorder Traversal: ");
            preorder_traversal(root);
            printf("\n");
            break;
        case 6:
            printf("Postorder Traversal: ");
            postorder_traversal(root);
            printf("\n");
            break;
        case 7:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}