#include <stdio.h>
int main()
{
    int arr[5] = {5, 3, 2, 7, 1}; // unsorted array given

    int a;
    int b;
    int size = 5;
    for (a = 0; a < size - 1; a++) // will be running till just before the last element
    {
        for (b = 0; b < size - 1-a; b++)  
    //b < size - 1 - a --> this skiips those one which are already been sorted.
    // otherwise it will give the out of bound error
        {
            if (arr[b] > arr[b + 1]) // comparing element at 1 with 2 position
            {
                //swapping done overhere
                int temp = arr[b];
                arr[b] = arr[b + 1];
                arr[b + 1] = temp;
            }
        }
    }
    // Printing sorted array
    for (a = 0; a < size; a++)
        printf("%d ", arr[a]);

    return 0;
}