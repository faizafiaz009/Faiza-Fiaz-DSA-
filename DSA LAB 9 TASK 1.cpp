
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

string infixToPostfix(string infix)
{
    string postfix = "";

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
    }

    while (top != -1)
    {
        postfix += pop();
    }

    return postfix;
}

int main()
{
    string exp1 = "A+B*C";
    string exp2 = "(A-B)*C";
    string exp3 = "A*B+C/D";

    cout << "Infix: " << exp1 << endl;
    cout << "Postfix: " << infixToPostfix(exp1) << endl;

    top = -1;

    cout << "\nInfix: " << exp2 << endl;
    cout << "Postfix: " << infixToPostfix(exp2) << endl;

    top = -1;

    cout << "\nInfix: " << exp3 << endl;
    cout << "Postfix: " << infixToPostfix(exp3) << endl;

    return 0;
}
