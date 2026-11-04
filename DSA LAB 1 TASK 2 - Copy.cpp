#include <iostream>
using namespace std;

int main()
{
    int arr[10];
    int positive = 0;
    int negative = 0;
    int zero = 0;

    cout << "Enter 10 numbers: ";

    for(int i = 0; i < 10; i++)
    {
        cin >> arr[i];

        if(arr[i] > 0)
        {
            positive++;
        }
        else if(arr[i] < 0)
        {
            negative++;
        }
        else
        {
            zero++;
        }
    }

    cout << "Positive Numbers = " << positive << endl;
    cout << "Negative Numbers = " << negative << endl;
    cout << "Zeros = " << zero << endl;

    return 0;
}