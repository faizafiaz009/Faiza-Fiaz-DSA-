#include <iostream>
using namespace std;

#define SIZE 6

int queue[SIZE];
int front = -1;
int rear = -1;

void issueToken()
{
    if (rear == SIZE - 1)
    {
        cout << "Waiting room is full!" << endl;
    }
    else
    {
        int token;
        cout << "Enter token number: ";
        cin >> token;

        if (front == -1)
            front = 0;

        rear++;
        queue[rear] = token;

        cout << "Token issued successfully!" << endl;
    }
}

void serveCustomer()
{
    if (front == -1 || front > rear)
    {
        cout << "Nobody is waiting!" << endl;
    }
    else
    {
        cout << "Customer served: " << queue[front] << endl;
        front++;

        if (front > rear)
        {
            front = -1;
            rear = -1;
        }
    }
}

void showWaiting()
{
    if (front == -1)
    {
        cout << "No customers waiting!" << endl;
    }
    else
    {
        cout << "Waiting customers: ";

        for (int i = front; i <= rear; i++)
        {
            cout << queue[i] << " ";
        }

        cout << endl;
    }
}

int main()
{
    int choice;

    do
    {
        cout << "\n--- BANK TOKEN SYSTEM ---" << endl;
        cout << "1. Issue Token" << endl;
        cout << "2. Serve Customer" << endl;
        cout << "3. Show Waiting Customers" << endl;
        cout << "4. Exit" << endl;

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                issueToken();
                break;

            case 2:
                serveCustomer();
                break;

            case 3:
                showWaiting();
                break;

            case 4:
                cout << "Program ended!" << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
        }

    } while (choice != 4);

    return 0;
}
