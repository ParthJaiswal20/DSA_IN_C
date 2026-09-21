#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int vector[]= {1,2,3,4,5};
    for(int parth : vector)
    {
        cout<<parth<<"\n";
    }
    return 0;
}