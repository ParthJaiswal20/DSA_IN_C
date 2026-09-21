#include <iostream>
using namespace std;
int main()
{
    int size; //TAKING THE SIZE FROM THE USER 
    cout << "enter the size of the array";
    cin >> size;
    int a;
    int arr[size];//MAKING AN ARRAY OF THAT SIZE 
    for (a = 0; a < size; a++)
    {
        cin >> arr[a];//TAKING THE INPUT IN THAT ARRAY
    }

    int hash[13] = {0}; /* USING A HASH ARRAY SUCH AS TO INCREASE THE VALUE OF THAT NUMBER IN A WHICH IS THE INDEX OF THE HASH 
    SUCH THAT WHEN THE ELEMENT AT ANY INDEX OF THE ARRAY IS SEND DO HASH'S THAT INDEX IT INCREMENT THE VALUE*/
    /*MENS NUMNBER 5 FROM ARRAY A WILL NOW BE TREATED AS INDEX OF HASH 5 AND AT THAT THE HASH IS HAVING 0 WHICH IS NOW INCREMENT BY `*/
    for (int i = 0; i < size; i++)
    {
        hash[arr[i]] += 1;
    }
    int b;
    cin >> b;
    while (b--)
    {
        int number;
        cin >> number;
        cout << hash[number];
    }
    return 0;
}