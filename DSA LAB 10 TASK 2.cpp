
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

void push(string word)
{
    Node* newNode = new Node;
    newNode->data = word;
    newNode->next = top;
    top = newNode;

    cout << "Typed: " << word << endl;
}

void pop()
{
    if (top == NULL)
    {
        cout << "Nothing to undo" << endl;
        return;
    }

    Node* temp = top;

    cout << "Undone: " << top->data << endl;

    top = top->next;
    delete temp;
}
void peek()
{
    if (top == NULL)
    {
        cout << "Editor is empty." << endl;
    }
    else
    {
        cout << "Last word: " << top->data << endl;
    }
}

int size()
{
    int count = 0;
    Node* temp = top;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    return count;
}

int main()
{
    int choice;
    string word;

    do
    {
        cout << "\n1. Type Word";
        cout << "\n2. Undo";
        cout << "\n3. Show Word Count";
        cout << "\n4. Show Last Word";
        cout << "\n5. Exit";

        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter word: ";
                cin >> word;
                push(word);
                cout << "Count = " << size() << endl;
                break;

            case 2:
                pop();
                cout << "Count = " << size() << endl;
                break;

            case 3:
                cout << "Word Count = " << size() << endl;
                break;

            case 4:
                peek();
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
