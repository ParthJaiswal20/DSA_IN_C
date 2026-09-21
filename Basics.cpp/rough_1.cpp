#include<iostream>
using namespace std;
int main()
{
    int size;
    cout<<"enter the size";
    cin>>size;
    int arr[size];
    int a;
    for(a=0;a<size;a++)
    {
        cin>>arr[size];
    }
    int hash[13]={0};
    for(int i = 0;i<size;i++)
    {
        hash[arr[i]] +=1;
    }

    int q;
    cin>>q;
    while(q--)
    {
        int number;
        cin>>number;
        cout<<hash[number];
    }
    return 0;
}