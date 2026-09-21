#include <iostream>
using namespace std;
int main()
{
    int a;
    int b;
    int c;
    for (a = 1; a <= 5; a++)
    {
        for (b = 1; b <= a; b++)
        {
            cout << "*";
        }
        cout << "\n";
    }
    for (a = 4; a >= 1; a--)
    {
        for (c = 1; c <= a; c++)
        {
            cout << "*";
        }
        cout << "\n";
    }
    return 0;
}