#include <iostream>
using namespace std;

int main()
{
    int rows, cols;

    cout << "Enter number of rows: ";
    cin >> rows;

    cout << "Enter number of columns: ";
    cin >> cols;

    int **arr = new int*[rows];

    for(int i = 0; i < rows; i++)
    {
        arr[i] = new int[cols];
    }

    cout << "\nEnter matrix elements:\n";

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            cin >> arr[i][j];
        }
    }

    cout << "\nMatrix is:\n";

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            cout << arr[i][j] << " ";
        }

        cout << endl;
    }

    for(int i = 0; i < rows; i++)
    {
        delete[] arr[i];
    }

    delete[] arr;

    arr = nullptr;

    return 0;
}