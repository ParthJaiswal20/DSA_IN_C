#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
    int a;
    int b;
    int c;
    for (a = 1; a <= 4; a++)
    {
        for (b = 0; b < a; b++)
        {
            cout << " ";
        }
        for (c = 4; c >= a; c--)
        {
            cout << a;
        }
        cout << "\n";
    }
    return 0;
}