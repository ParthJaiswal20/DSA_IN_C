#include<iostream>
using namespace std;
void intersection(int *d,int *e,int c)
{
    int a; int b;
    for(a=0;a<c;a++)
    {
        for(b=0;b<c;b++)
       {
            if(d[a]==e[b])
            {
                cout<<"The Macthed elements are\n";
                cout<<d[a]<<"\n";
            }
       }
}
}       
int main()
{
    int size; int a;
    cout<<"Enter the size\n";
    cin>>size;
    int arr[size];
    int brr[size];
    cout<<"Enter the elements of a\n";
    for(a=0;a<size;a++)
    {
        cin>>arr[a];
    }
    cout<<"enter the elements of b\n";
    for(a=0;a<size;a++)
    {
        cin>>brr[a];
    }
    intersection(arr,brr,size);
    return 0;
}