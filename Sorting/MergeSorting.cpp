#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;    // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1; // starting index of right half of arr

    // storing elements in the temporary array in a sorted manner//
    //------------------------------------------------------------------
    while (left <= mid && right <= high)
    // as left will also be moving towards the mid and right will also me moving to the high
    {
        if (arr[left] <= arr[right])
        {
            // the array splited into left and right side unke beach me comparison ho raha hai

            // as temp is a vector whose size can inc every time , thats why we pushing it jabarjasti
            temp.push_back(arr[left]);

            // as alredy know left will inc and move towards the mid -->
            left++;
        }
        else
        {
            // if element at left is smaller then push right side element
            temp.push_back(arr[right]);
            // now right will move to next element till it reaches high -->
            right++;
        }
    }       

    // if elements on the left half are still left //
    while (left <= mid)
    {
        /*if after comparison also elememts are left
        //then push all elemetns of the left to the temp
        dont need to check and check karne ke liye koi hai bhi nahi*/
        temp.push_back(arr[left]);
        left++;
    }
    /*if elements on the right half are still left , and left side
    elements are over, no more left */
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr
    // when done all work now pass to the array to store them correctly
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}

//---------------------------------------------------------------------

void mergeSort(vector<int> &arr, int low, int high)
{
    if (low >= high)
        return;
    int mid = (low + high) / 2;
    mergeSort(arr, low, mid);      // left half
    mergeSort(arr, mid + 1, high); // right half
    merge(arr, low, mid, high);    // merging sorted halves
}

int main()
{

    vector<int> arr = {9, 4, 7, 6, 3, 1, 5};
    int n = 7;

    cout << "Before Sorting Array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    mergeSort(arr, 0, n - 1);
    cout << "After Sorting Array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}