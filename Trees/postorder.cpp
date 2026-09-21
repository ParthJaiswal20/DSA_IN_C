#include <iostream>
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
    struct node *Newnode = new node;
    Newnode->data = val;
    Newnode->left = NULL;
    Newnode->right = NULL;
    return Newnode;
}

//POSTORDER TRAVERSING
void postorder(struct node *root, vector<int> &arr)
// root-> the current node of the tree
// arr is the array to store the values while traversing
{
    if (root == NULL)
    {
        return;
    }
    // this is the left side
    postorder(root->left, arr);
    // this is for right side
    postorder(root->right, arr);
    // below one is for the root one, direct push when it comes to the root
    arr.push_back(root->data); // directly pushing the root in the arr after left and right traversing is done
    /* so when the left and right side traversing is done completely, then it will directly saving the roots node value
       it in the arr by pushing it in the arr.

       Simply, you can understand it like when both left and right traversing is done with the help of the root,
       we are directly assigning the root's data now and forcefully pushing it into the stack.
    */
}

vector<int> postOrder(struct node *root)
{
    // Create an empty vector to store postorder traversal values
    vector<int> arr;
    // Call the postorder traversal function
    postorder(root, arr);
    // Return the resulting vector containing postorder traversal values
    return arr;
}

int main()
{
    // Creating a sample binary tree
    struct node *root = createnode(1);
    root->left = createnode(2);
    root->right = createnode(3);
    root->left->left = createnode(4);
    root->left->right = createnode(5);

    // Getting postorder traversal
    vector<int> result = postOrder(root);

    // Displaying the postorder traversal result
    cout << "Postorder Traversal: ";
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
