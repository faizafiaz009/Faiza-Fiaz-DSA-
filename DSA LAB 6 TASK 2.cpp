#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
};

Node* head = NULL;


void insert(int value)
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
}

void deleteAtEnd()
{
    if(head == NULL)
    {
        cout << "List is empty\n";
        return;
    }

    if(head->next == NULL)
    {
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;

    while(temp->next->next != NULL)
    {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = NULL;
}


void deleteAtPosition(int pos)
{
    if(head == NULL)
    {
        cout << "List is empty\n";
        return;
    }

    if(pos < 1)
    {
        cout << "Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* temp = head;

    for(int i = 1; i < pos - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if(temp == NULL || temp->next == NULL)
    {
        cout << "Position not found\n";
        return;
    }

    Node* del = temp->next;
    temp->next = del->next;

    delete del;
}

// Display
void display()
{
    Node* temp = head;

    while(temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL\n";
}

int main()
{
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);

    cout << "Original List: ";
    display();

    deleteAtEnd();

    cout << "After deleting last node: ";
    display();

    deleteAtPosition(2);

    cout << "After deleting position 2: ";
    display();

    return 0;
}