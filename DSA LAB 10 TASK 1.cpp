
#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    string data;
    Node* next;
};

Node* top = NULL;

void push(string page)
{
    Node* newNode = new Node;
    newNode->data = page;
    newNode->next = top;
    top = newNode;

    cout << "Visited: " << page << endl;
}

void pop()
{
    if (top == NULL || top->next == NULL)
    {
        cout << "Cannot go back" << endl;
        return;
    }

    Node* temp = top;
    top = top->next;
    delete temp;

    cout << "Current page: " << top->data << endl;
}


void peek()
{
    if (top == NULL)
    {
        cout << "No page opened." << endl;
    }
    else
    {
        cout << "Current page: " << top->data << endl;
    }
}


void display()
{
    if (top == NULL)
    {
        cout << "History is empty." << endl;
        return;
    }

    Node* temp = top;

    cout << "Browser History:" << endl;

    while (temp != NULL)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}

int main()
{
    int choice;
    string page;

    do
    {
        cout << "\n1. Visit Page";
        cout << "\n2. Back";
        cout << "\n3. Current Page";
        cout << "\n4. History";
        cout << "\n5. Exit";

        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter page name: ";
                cin >> page;
                push(page);
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                cout << "Program ended." << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
        }

    } while (choice != 5);

    return 0;
}
