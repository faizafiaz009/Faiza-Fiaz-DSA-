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

void deleteByValue(int value)
{
    if(head == NULL)
    {
        cout << "Value not found\n";
        return;
    }

    if(head->data == value)
    {
        Node* temp = head;
        head = head->next;

        delete temp;

        cout << "Value deleted successfully\n";
        return;
    }

    Node* temp = head;

    while(temp->next != NULL && temp->next->data != value)
    {
        temp = temp->next;
    }

    if(temp->next == NULL)
    {
        cout << "Value not found\n";
    }
    else
    {
        Node* del = temp->next;

        temp->next = del->next;

        delete del;

        cout << "Value deleted successfully\n";
    }
}

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

    deleteByValue(10);

    cout << "After deleting 10: ";
    display();

    deleteByValue(30);

    cout << "After deleting 30: ";
    display();

    deleteByValue(100);

    cout << "After trying to delete 100: ";
    display();

    return 0;
}