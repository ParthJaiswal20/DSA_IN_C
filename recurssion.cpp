#include <iostream>
using namespace std;

void print_fun(int count)
{
    if (count == 0)
        return;

    cout << "parth" << endl;
    count--;
    print_fun(count);
}

int main()
{

    int count;
    cout<<"lode";
    cin>> count;
    print_fun(count);
    return 0;
}