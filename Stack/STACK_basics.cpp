//here in this code we are implementing the stack function using array.
#include <bits/stdc++.h>
using namespace std;
class Stack
{
    int size;
    int *arr;
    int top;
public:
    Stack()
    {
        top = -1; 
        size = 1000;
        arr = new int[size];
    }
    void push(int x)    //this is for geeting the function in the stack
    {
        top++; //as i am using array for this therefore setting the top to -1 and now moving the top to 0 by adding 1 which is arr[0].
        arr[top] = x;
    }
    int pop()   //this is for removing the elements in the stack
    {
        int x = arr[top];
        top--;
        return x;
    }
    int Top()   /*this if for returning something , as we are returning something threfore int in this , while other are for 
    adding or remvoing therefore no need to return anything in this*/
    {
        return arr[top]; //jsut return me the element
    }
    int Size()  //this for finding the size of the stack
    {
        return top + 1; /*in this whether still u have top as -1 then the size will be 0, it is because 
        in this we are using the array , and in array we start the index form 0 and size from 1 , therefore 
        if there are 4 elements present in the array the size will give 4 but the index of the elements will run from */
    }
};
int main()
{

    Stack s;
    s.push(6);
    s.push(3);
    s.push(7);
    cout << "Top of stack is before deleting any element " << s.Top() << endl;
    cout << "Size of stack before deleting any element " << s.Size() << endl;
    cout << "The element deleted is " << s.pop() << endl;
    cout << "Size of stack after deleting an element " << s.Size() << endl;
    cout << "Top of stack after deleting an element " << s.Top() << endl;
    return 0;
}