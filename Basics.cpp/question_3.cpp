#include <stdio.h>
#include <iostream>
using namespace std;
int DecToBin(int b)
{
    int sum = 0;
    int rem;
    int pow = 1; /*hame yaha par jo bhi remainder aa raha tha use bar bar aage ke taraf join karte jana tha. so thats why this power as 1 ,
means 1 aya remainder and then u got 0 , so now u have to put this 0 before the 1 and also we are increasing the vlaue of it again and again
by 1 -> 10 ->100*/
    while (b != 0)
    {
        rem = b % 2;
        sum = sum + (rem * pow);
        pow = pow * 10; /*this is what i am talking about*/
        b = b / 2;
    }
    return sum;
}
int main()
{
    int a;
    int b;
    cout << "enter the number\n";
    cin >> a;
    b = DecToBin(a);
    cout << b;
    return 0;
}