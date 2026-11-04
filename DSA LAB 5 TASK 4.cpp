#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
};

Node* head = NULL;

void insertStart(int value)
{
    Node* newNode = new Node;

    newNode->data = value;
    newNode->next = head;
    head = newNode;

    cout << "Node inserted at start.\n";
}

// Insert at End
void insertEnd(int value)
{
    Node* newNode = new Node;

    newNode->data = value;
    newNode->next = NULL;

    if(head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node* temp = head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    cout << "Node inserted at end.\n";
}

// Insert After Given Value
void insertMiddle(int key, int value)
{
    Node* temp = head;

    while(temp != NULL && temp->data != key)
    {
        temp = temp->next;
    }

    if(temp == NULL)
    {
        cout << "Value not found!\n";
        return;
    }

    Node* newNode = new Node;

    newNode->data = value;
    newNode->next = temp->next;
    temp->next = newNode;

    cout << "Node inserted successfully.\n";
}

void display()
{
    Node* temp = head;

    if(head == NULL)
    {
        cout << "List is empty.\n";
        return;
    }

    cout << "Linked List: ";

    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main()
{
    int choice, value, key;
    int n;

    cout << "Enter number of initial nodes: ";
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cout << "Enter value: ";
        cin >> value;

        insertEnd(value);
    }

    do
    {
        cout << "\n----- LINKED LIST MENU -----\n";
        cout << "1. Insert at Start\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert in Middle\n";
        cout << "4. Display List\n";
        cout << "5. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                insertStart(value);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> value;
                insertEnd(value);
                break;

            case 3:
                cout << "Enter existing value: ";
                cin >> key;

                cout << "Enter new value: ";
                cin >> value;

                insertMiddle(key, value);
                break;

            case 4:
                display();
                break;

            case 5:
                cout << "Program ended.";
                break;

            default:
                cout << "Invalid choice!";
        }

    } while(choice != 5);

    return 0;
}