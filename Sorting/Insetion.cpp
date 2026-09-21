#include <iostream>
using namespace std;

int main() 
{
    int n = 5;
    int arr[n] = {29, 10, 14, 37, 13};
    int a, b, temp;
    // Outer loop starts from the second element (index 1)
    for (a = 1; a < n; a++) 
    {
        temp = arr[a];  // Store the current element
        b = a - 1;      // Start comparing with the element before it
        // Shift elements to the right if they are greater than temp
        while (b >= 0 && arr[b] > temp) 
        {
            arr[b + 1] = arr[b];  // Move element to the right
            b--;  // Move left
        }
        // Place the current element at its correct position
        arr[b + 1] = temp;
    }
    // Printing the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}