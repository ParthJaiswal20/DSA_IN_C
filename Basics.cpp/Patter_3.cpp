#include <iostream>
using namespace std;
int main()
{
    int a;
    int b;
    for (a = 1; a <= 3; a++)
    {
        for (b = 1; b <= a; b++)
        {
            cout << "* ";
        }
        cout << "\n";
    }
    return 0;
}