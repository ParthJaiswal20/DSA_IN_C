#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partion(int arr[], int low, int high)
{
    //[5,1,8,0,2] --> in this the pivot taken is 5 and the a is the formward pointer at 1 and b is the backward coming pointer
    // which is at 2.
    int pivot = arr[low]; //set the pivot at the 0th index value of the array .
    int forward = low + 1; // forward is set at the 1st index element of the array.
    int backward = high; // backward is set at the last element of the array.

    while (forward <= backward) // until and unless the forward is not crssoing the backward comparion should go on 
    {
        while (forward <= high && arr[forward] <= pivot) // while forward is <= high means forward moving this direction --->
// backward moving this direction <--- and we have to swap only when we found the element greater than the pivot therefore thats why 
// arr[forward] < = pivot , we keep moving in this direction -->
        {
            forward++; // moving from left side to right side.
        }
        while (arr[backward] > pivot) // as if for ex pivot is 4 and arr[backward] is 6 so need to change as we need bigger element than pivot
// in the right side only
// and only need to swap them when found element less than the pivot 
// 4->(6)  <--> (3) so in this case we want to keep 3 at the left side and 6 at the right side therefore we will swap them.
        {
            backward--; // coming right side to left side.
        }
        if (forward < backward)
        {
            swap(&arr[forward], &arr[backward]);
        }
    }
        swap(&arr[low],&arr[backward]);
    return backward;
}

void quicksort(int arr[], int low, int high)
{
    if (low < high)
    {
        int call = partion(arr,low,high);

        quicksort(arr,low,call-1);
        quicksort(arr,call+1,high);
    }
}
int main()
{
    int arr[] = {5, 1, 8, 0, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    quicksort(arr, 0, n - 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}