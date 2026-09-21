#include <stdio.h>
#include <unordered_map>
#include <iostream>
using namespace std;
int main()
{
    // creation
    unordered_map<string, int> mpp;

    // insertion
    mpp["parth"] = 1;
    mpp["jaiswal"] = 1;

    //------------------------------------------------------

    // update the value
    mpp["parth"] = 2;

    //------------------------------------------------------

    // accessing the elements that are present
    cout << mpp["parth"] << endl;
    cout << mpp["jaiswal"] << endl;

    //------------------------------------------------------

    // accssing of the key can also be done using the cpp function in build that is .at
    cout << mpp.at("parth") << endl;

    // trying to access those elements that are not present.
    cout << mpp["jitendra"] << endl;
    // like this when u try to acess that value that are not present in the unordered map then it will make an
    // entry for the unknown key corresponding to 0;

    cout << "the size of the mpp is -> " << mpp.size() << endl;

    //------------------------------------------------------

    // to check if agar koi entry + uski count diya gaaya hai ki nahi in the map

    // case1 :- when the element is given

    cout << "this is present in the map-> " << mpp.count("parth") << endl;

    // case2:- when the element was not given in the map

    cout << "this is not present in the map-> " << mpp.count("sangeeta") << endl;

    cout << "this is the size of the map before the erase-> " << mpp.size() << endl;

    //------------------------------------------------------

    // erase from the map

    //mpp.erase("parth");

    cout << "this is the size of the map after the erase-> " << mpp.size() << endl;

    //------------------------------------------------------

    // to print the map values:-
    for (auto i : mpp)
    {
        cout << i.first << " " << i.second<< endl;
    }
-
    return 0;
}