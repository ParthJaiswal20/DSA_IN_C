#include <iostream>
using namespace std;
int fact(int c)
{
    int d;
    int factt = 1;
    for (d = 1; d <= c; d++)
    {
        factt = factt * d;
    }
    return factt;
}

int main()
{
    int a;
    int b;
    cout << "enter the number";
    cin >> a;
    b = fact(a);
    cout << b;
    return 0;
}