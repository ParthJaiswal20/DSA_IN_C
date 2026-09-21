#include <iostream>
using namespace std;
int main()
{
    int n = 5;
    int arr[n] = {1, 2, 3, 4, 5};
    int a, b;
    int end;
    for (a = 0; a < n; a++)
    {
        for (end = a; end < n; end++) // if u remove this then the output will only contain the last one means the 12345
        // 2345,345,45,5
        {
            for (b = a; b <= end; b++)
            {
                cout << arr[b];
            }
            cout << " ";
        }
    }
    return 0;
}