#include <iostream>
using namespace std;

int main()
{
    int num;
    int *ptr;

    cout << "Enter a number: ";
    cin >> num;

    ptr = &num;

    cout << "Before Modification = " << num << endl;

    *ptr = 50;

    cout << "After Modification = " << num << endl;

    return 0;
}