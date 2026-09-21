// in this code we are using queue as an array, or implementing the queue through or using arrays
#include <bits/stdc++.h>
using namespace std;
class Queue
{
    int *arr; 
    int start, end, currSize, maxSize;
public:
    Queue()
    {
        arr = new int[16];
        start = -1;
        end = -1;
        currSize = 0;
    }
    Queue(int maxSize)
    {
        (*this).maxSize = maxSize;
        arr = new int[maxSize];
        start = -1;
        end = -1;
        currSize = 0;
    }
    void push(int newElement)
    {
        if (currSize == maxSize)    //this is the case when u cannot push in it.
        {
            cout << "Queue is full\nExiting..." << endl;
            exit(1);
        }
        if (end == -1)  //this is the case when both are just starting , or this is the initial stage of adding the elements
        {
            start = 0;
            end = 0;
        }
        else
            end = (end + 1) % maxSize;
        arr[end] = newElement;
        cout << "The element pushed is " << newElement << endl;
        currSize++;
    }
    int pop()   //it is for deleting the elements , it can only be done when there is something in the queue
    {
        if (start == -1)    //or u can also say that the current size = 0 , and if staisfies then we can say that koi element hai hi nahi
        {
            cout << "Queue Empty\nExiting..." << endl;
        }
        int popped = arr[start]; /*as queue follow FIFO threfore the element which will be removed first will be the first element
        which can be assessed with the help of the start , as when u will remvoe the element the data will get corrupt . therefore in 
        place of loosing the data we just 1st store it in the variable popped and then we remove it so as to know which element have
        been removed*/
        if (currSize == 1)
        {
            start = -1;
            end = -1;
        }
        else
         start = (start + 1) % maxSize;
        currSize--;
        return popped; 
    }
    int top()
    {
        if (start == -1)
        {
            cout << "Queue is Empty" << endl;
            exit(1);
        }
        return arr[start];
    }
    int size()
    {
        return currSize;
    }
};
int main()
{
    Queue q(6);
    q.push(4);
    q.push(14);
    q.push(24);
    q.push(34);
    cout << "The peek of the queue before deleting any element " << q.top() << endl;
    cout << "The size of the queue before deletion " << q.size() << endl;
    cout << "The first element to be deleted " << q.pop() << endl;
    cout << "The peek of the queue after deleting an element " << q.top() << endl;
    cout << "The size of the queue after deleting an element " << q.size() << endl;
    return 0;
}