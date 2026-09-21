// question:- Find the number which is occuring the maximum number of time.
#include<iostream>
using namespace std;
#include <unordered_map>
#include <stdio.h>
#include <climits>  // → Needed for INT_MIN

int main()
{
    unordered_map<int,int>mpp;

    int size1;
    cout << "Enter size of array: ";
    cin >> size1;

    int arr[size1];   // → Array with user input size
    cout << "Enter elements: ";
    for(int i = 0; i < size1; i++)
    {
        cin >> arr[i];   // → Taking input for array
    }

    for(int i = 0; i<size1; i++)
    {
        mpp[arr[i]]++;   // → count[arr[i]] changed to mpp[arr[i]]
    }

    int maxi = INT_MIN;
    int ans = -1;
    for(auto i:  mpp)
    {
        if(i.second>maxi)
        {
            maxi = i.second;
            ans = i.first;
        }
    }
    cout << "Number occurring maximum times: " << ans << endl;
    return 0;
}