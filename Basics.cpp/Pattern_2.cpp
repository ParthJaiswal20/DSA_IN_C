#include<iostream>
using namespace std;
int main()
{
    int a ; int b; int c =0; 
    for(a=1;a<=3;a++)
    {
        for(b=1;b<=3;b++)
        {
            c = c+1;
            cout<<c;
        }
        cout<<"\n";
    }
    return 0;
} 