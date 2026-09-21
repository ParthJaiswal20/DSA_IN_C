#include<iostream>
using namespace std;
int main()
{
    int a; int b; int c;
    for(a=5;a>=1;a--)
    {
        for(b=5;b>=a;b--)
        {
            cout<<" ";
        }
        for(c=1;c<=(2*a)-1;c++)
        {
            cout<<"*";
        }
        cout<<"\n";
    }
    return 0;
}