#include <iostream>
using namespace std;

int main()
{
    int num = 10;

    int *p = &num;

    int **pp = &p;

    cout << "Original value: " << num << endl;

    **pp = 50;

    cout << "Modified value: " << num << endl;

    return 0;
}