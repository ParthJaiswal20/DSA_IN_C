#include <iostream>
using namespace std;
void reverseArray(int arr[], int size)
{
    int start = 0, end = size - 1;
    while (start < end)
    {
        swap(arr[start], arr[end]);
        start++; // points it to the begining of an array
        end--;   // it points it to the last element of an array
        /*it swaps the element form the start to the element in the end , then start starts moving in the forward direction and end
        starts in the backward direction untill they meet in the middle*/
        /*First swap: arr[0] and arr[5] (1 ↔ 6).
        Second swap: arr[1] and arr[4] (2 ↔ 5).
        Third swap: arr[2] and arr[3] (3 ↔ 4).*/
        // and your array is now reversed
    }
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int size = 6;
    int a;

    reverseArray(arr, size);
    for (a = 0; a < size; a++)
    {
        cout << arr[a] << " ";
    }
    return 0;
}