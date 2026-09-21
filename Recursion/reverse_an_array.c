#include <stdio.h>

// // USING TWO POINTERS + RECURSSION
// void reverse(int left, int right)
// {
//     int arr[5] = {1, 2, 3, 4, 5};
//     if (left == right) // base case if they meet both at the same point
//         return;
//     else
//         swap(arr[left], arr[right]);
//     reverse(left++, right--); // moved the left in front --> direction and moved the right in the backward direction <--
// }
// int main()
// {
//     int left = 0;
//     int right = 4;
//     reverse(left, right);
//     return 0;
// }

// USING ONLY ONE VARIABLE TO SOLVE ::-
void reverse(int mover, int arr[], int size)
{
    if (mover >= size / 2)
        return;
    int temp = arr[mover];
    arr[mover] = arr[size - mover - 1];
    arr[size - mover - 1] = temp;
    reverse(mover + 1, arr, size);
}
int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int size = 5;
    int mover = 0;
    reverse(mover, arr, size);
    for (int inner = 0; inner < size; inner++)
    {
        printf("%d ", arr[inner]);
    }
    return 0;
}