#include <iostream>
using namespace std;
int main()
{
    int a[5];
    int max;
    int min;
    int b;
    int c;
    cout << "enter the elements\n";
    for (b = 0; b < 5; b++)
    {
        cin >> a[b];
    }
    max = a[0];
    min = a[0];

    for (c = 0; c < 5; c++)
    {
        if (a[c] > max)
        {
            max = a[c];
        }

        if (a[c] < min)
        {
            min = a[c];
        }
    }
    cout << max;
    cout << "\n";
    cout << min;
    return 0;
}