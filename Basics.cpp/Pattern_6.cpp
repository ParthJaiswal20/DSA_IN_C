#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int a; int b; int c;
    for(a=4;a>=1;a--)
    {
        for(c=0;c<3;c++)
        {
            cout<<"";
        }
        for(b=1;b<=a;b++)
        {
            cout<<a;
        }
        cout<<"\n";
    }
    return 0;
}