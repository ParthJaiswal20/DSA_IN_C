#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
    int a; int b;
    for(a=0;a<5;a++)
    {
        for(b=a+1;b>0;b--)
        {
            cout<<b;
        }
        cout<<"\n";
    }
    return 0;
}