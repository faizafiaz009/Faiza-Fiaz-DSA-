```cpp
#include <iostream>
#include <string>
using namespace std;

char stack[50];
int top = -1;

void push(char x)
{
    top++;
    stack[top] = x;
}

char pop()
{
    char x = stack[top];
    top--;
    return x;
}

int precedence(char op)
{
    if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0;
}

int main()
{
    string infix = "(A+B)*C";
    string postfix = "";

    cout << "Character\tStack\t\tPostfix" << endl;

    for (int i = 0; i < infix.length(); i++)
    {
        char ch = infix[i];

        if (ch >= 'A' && ch <= 'Z')
        {
            postfix += ch;
        }

        else if (ch == '(')
        {
            push(ch);
        }

        else if (ch == ')')
        {
            while (top != -1 && stack[top] != '(')
            {
                postfix += pop();
            }

            pop();
        }

        else
        {
            while (top != -1 && stack[top] != '(' &&
                   precedence(stack[top]) >= precedence(ch))
            {
                postfix += pop();
            }

            push(ch);
        }

        cout << ch << "\t\t";

        if (top == -1)
            cout << "Empty";
        else
        {
            for (int j = 0; j <= top; j++)
                cout << stack[j];
        }

        cout << "\t\t" << postfix << endl;
    }

    while (top != -1)
    {
        postfix += pop();
    }

    cout << "End\t\tEmpty\t\t" << postfix << endl;

    cout << "\nFinal Postfix: " << postfix << endl;

    return 0;
}
```