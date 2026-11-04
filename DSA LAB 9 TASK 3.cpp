
#include <iostream>
using namespace std;

#define MAX 5

int stack[MAX];
int top = -1;

void push(int x)
{
    if (top == MAX - 1)
    {
        cout << "Stack Overflow!" << endl;
    }
    else
    {
        top++;
        stack[top] = x;
        cout << x << " pushed into stack." << endl;
    }
}

void pop()
{
    if (top == -1)
    {
        cout << "Stack Underflow!" << endl;
    }
    else
    {
        cout << "Popped: " << stack[top] << endl;
        top--;
    }
}


int search(int x)
{
    int steps = 1;

    for (int i = top; i >= 0; i--)
    {
        if (stack[i] == x)
        {
            return steps;
        }

        steps++;
    }

    return -1;
}

int main()
{
    int num;

    cout << "Enter 5 integers:" << endl;

    for (int i = 0; i < MAX; i++)
    {
        cin >> num;
        push(num);
    }
    cout << "\nTrying to push sixth integer:" << endl;
    push(60);


    cout << "\nEnter a value to search: ";
    cin >> num;

    int result = search(num);

    if (result != -1)
        cout << "Value found at " << result << " step(s) from top." << endl;
    else
        cout << "Value not found!" << endl;

    cout << "\nSearching for 999:" << endl;

    result = search(999);

    if (result == -1)
        cout << "Value not found! Returned -1." << endl;
    else
        cout << "Value found at " << result << " step(s) from top." << endl;

    cout << "\nPopping all elements:" << endl;

    while (top != -1)
    {
        pop();
    }
    cout << "\nTrying to pop again:" << endl;
    pop();

    return 0;
}
