#include <iostream>
using namespace std;
#include <string>
class teacher
{
private: // these are used for those things which we dont want to be allowed by everyone to use or see.
    double salary;

public: // this is for telling the computer that this variables I am declaring overhere make them use by all
    string subject;
    string dept;
    string name;

    void changeDept(string newDept) // this is called method making
    {
        dept = newDept;
    }

    // this function is also known as setter
    void setSalary(double s) // by use of the below 2 functions we have gotten the access of the salary
    {
        salary = s;
    }

    // this function is also known as getter
    double getSalary()
    {
        return salary;
    }
};

int main()
{
    teacher t1;        // this is called object declaration
    t1.name = "parth\n"; // assigning the values by the help of object name and the dot operator
    t1.subject = "computer\n";
    t1.setSalary(1000);
    cout << t1.name;
    cout << t1.subject;
    cout<<t1.getSalary();
    return 0;
}