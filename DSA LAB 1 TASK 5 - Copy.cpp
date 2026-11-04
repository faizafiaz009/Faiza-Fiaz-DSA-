#include <iostream>
using namespace std;

struct Student
{
    string name;
    int rollNo;
    float marks;
};

int main()
{
    Student s;

    cout << "Enter Student Name: ";
    cin >> s.name;

    cout << "Enter Roll Number: ";
    cin >> s.rollNo;

    cout << "Enter Marks: ";
    cin >> s.marks;

    cout << "\nStudent Details:" << endl;
    cout << "Name = " << s.name << endl;
    cout << "Roll Number = " << s.rollNo << endl;
    cout << "Marks = " << s.marks << endl;

    if(s.marks >= 50)
    {
        cout << "Result = Pass";
    }
    else
    {
        cout << "Result = Fail";
    }

    return 0;
}