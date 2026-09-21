#include <iostream>
using namespace std;
int linearsearch(int arr[])
{
    int b;
    int a;
    cout << "enter the element to search\n";
    cin >> a;
    for (b = 0; b < 4; b++)
    {
        if (arr[b] == a)
        {
            cout << "the index is\n";
            cout << b;
        }
    }
}
int main()
{
    int arr[4] = {1, 2, 3, 4};
    int d;
    d = linearsearch(arr);
    cout << d;
    return 0;
}