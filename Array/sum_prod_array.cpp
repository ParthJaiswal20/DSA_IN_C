// sum and product of all numbers in an array
#include <iostream>
using namespace std;
void sum_product(int *arr, int size) // mistakes done was not passing the address was passing the value
{
    int sum = 0;
    int product = 1;
    int a;
    for (a = 0; a < size; a++)
    {
        sum = sum + arr[a];
        product = product * arr[a];
    }
    cout << "the sum is\n"
         << sum << "\n"
         << "the product is\n"
         << product;
}
int main()
{
    int size;
    int a;
    cout << "enter the size\n";
    cin >> size;
    int arr[size];
    cout << "enter the elements\n";
    for (a = 0; a < size; a++)
    {
        cin >> arr[a];
    }
    sum_product(arr, size); // u have to just pass the address not the whole array
    return 0;
}