#include <iostream>
using namespace std;

int main()
{
    int arr[5] = {10, 20, 30, 40, 50};

    int search = 40;
    int low = 0;
    int high = 4;
    int mid;
    int found = -1;

    while(low <= high)
    {
        mid = (low + high) / 2;

        if(arr[mid] == search)
        {
            found = mid;
            break;
        }
        else if(search > arr[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    if(found != -1)
    {
        cout << "Element found at index: " << found;
    }
    else
    {
        cout << "Element not found";
    }

    return 0;
}