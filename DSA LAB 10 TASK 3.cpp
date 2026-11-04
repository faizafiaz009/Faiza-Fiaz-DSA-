
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
};

Node* top = NULL;

void push(int value)
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

int pop()
{
    if (top == NULL)
    {
        return -1;
    }

    Node* temp = top;
    int value = top->data;

    top = top->next;
    delete temp;

    return value;
}

int main()
{
    int num;

    cout << "Enter decimal number: ";
    cin >> num;

    if (num < 0)
    {
        cout << "Please enter a non-negative number." << endl;
        return 0;
    }

    if (num == 0)
    {
        cout << "Binary: 0" << endl;
    }
    else
    {
        while (num > 0)
        {
            int remainder = num % 2;
            push(remainder);
            num = num / 2;
        }

        cout << "Binary: ";

        while (top != NULL)
        {
            cout << pop();
        }

        cout << endl;
    }

    return 0;
}
