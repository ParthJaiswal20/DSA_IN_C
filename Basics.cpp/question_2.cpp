#include <iostream>
using namespace std;
int digitcal(int c)
{
    int rem;
    int sum = 0;
    while (c != 0)
    {
        rem = c % 10;
        sum = sum + rem;
        c  = c / 10;
    }
    return sum;
}
int main()
{
    int a;
    int d;
    cout << "enter the number";
    cin >> a;
    d = digitcal(a);
    cout << d;
    return 0;
}