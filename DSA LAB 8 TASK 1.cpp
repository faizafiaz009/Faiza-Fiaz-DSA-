
#include <iostream>
using namespace std;

int main()
{
    int arr[10];
    int choice, key;

    cout << "Enter 10 integers: " << endl;

    for (int i = 0; i < 10; i++)
    {
        cin >> arr[i];
    }

    do
    {
        cout << "\n===== MENU =====" << endl;
        cout << "1. Selection Sort" << endl;
        cout << "2. Bubble Sort" << endl;
        cout << "3. Insertion Sort" << endl;
        cout << "4. Binary Search" << endl;
        cout << "5. Display Array" << endl;
        cout << "6. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
            {
       
                for (int i = 0; i < 9; i++)
                {
                    int minIndex = i;

                    for (int j = i + 1; j < 10; j++)
                    {
                        if (arr[j] < arr[minIndex])
                        {
                            minIndex = j;
                        }
                    }

                    int temp = arr[i];
                    arr[i] = arr[minIndex];
                    arr[minIndex] = temp;
                }

                cout << "Array sorted using Selection Sort." << endl;
                break;
            }

            case 2:
            {
                for (int i = 0; i < 9; i++)
                {
                    for (int j = 0; j < 9 - i; j++)
                    {
                        if (arr[j] > arr[j + 1])
                        {
                            int temp = arr[j];
                            arr[j] = arr[j + 1];
                            arr[j + 1] = temp;
                        }
                    }
                }

                cout << "Array sorted using Bubble Sort." << endl;
                break;
            }

            case 3:
            {
                for (int i = 1; i < 10; i++)
                {
                    int key = arr[i];
                    int j = i - 1;

                    while (j >= 0 && arr[j] > key)
                    {
                        arr[j + 1] = arr[j];
                        j--;
                    }

                    arr[j + 1] = key;
                }

                cout << "Array sorted using Insertion Sort." << endl;
                break;
            }

            case 4:
            {
              
                for (int i = 0; i < 9; i++)
                {
                    for (int j = 0; j < 9 - i; j++)
                    {
                        if (arr[j] > arr[j + 1])
                        {
                            int temp = arr[j];
                            arr[j] = arr[j + 1];
                            arr[j + 1] = temp;
                        }
                    }
                }

                cout << "Enter number to search: ";
                cin >> key;

                int low = 0;
                int high = 9;
                int mid;
                bool found = false;

                while (low <= high)
                {
                    mid = (low + high) / 2;

                    if (arr[mid] == key)
                    {
                        found = true;
                        break;
                    }
                    else if (arr[mid] < key)
                    {
                        low = mid + 1;
                    }
                    else
                    {
                        high = mid - 1;
                    }
                }

                if (found)
                {
                    cout << "Number found at index " << mid << endl;
                }
                else
                {
                    cout << "Number not found." << endl;
                }

                break;
            }

            case 5:
            {
                cout << "Array elements: ";

                for (int i = 0; i < 10; i++)
                {
                    cout << arr[i] << " ";
                }

                cout << endl;
                break;
            }

            case 6:
                cout << "Program exited." << endl;
                break;

            default:
                cout << "Invalid choice! Try again." << endl;
        }

    } while (choice != 6);

    return 0;
}