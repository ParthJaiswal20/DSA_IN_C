#include<iostream>
using namespace std;
#include <vector>
int main()
{
    vector<int>vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.pop_back();
    for(int parth:vec)
    {   
        cout<<parth;
    }
    return 0;
}