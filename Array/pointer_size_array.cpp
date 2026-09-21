#include <iostream>
using namespace std;
void sizee(int *a) // taking the address THIS IS HOW U PASS THE ARRAY FROM ONE FUNCTION TO ANOTHER FUNCTION
{
    int b;
    b = sizeof(a);
    cout << "the size of the pointer is " << b;
    /*Inside sizee, the sizeof operator is used on the pointer (int *a) to determine the size of the pointer itself, not the array.*/
}
int main()
{
    int size;
    int a;
    cout << "enter the size\n";
    cin >> size;
    int arr[size];
    cout << "Enter the elements\n";
    for (a = 0; a < size; a++)
    {
        cin >> arr[a];
    }

    cout << "entered elements are\n";
    for (a = 0; a < size; a++)
    {
        cout << arr[a] << "\n";
    }
    sizee(arr); // passing an array arr to the function
    return 0;
}