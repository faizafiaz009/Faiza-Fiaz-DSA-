#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* prev;
    Node* next;
};

Node* head = NULL;

void insertStart(int value)
{
    Node* newNode = new Node;

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;

    if(head != NULL)
    {
        head->prev = newNode;
    }

    head = newNode;
}

void insertAfter(int key, int value)
{
    Node* temp = head;

    while(temp != NULL && temp->data != key)
    {
        temp = temp->next;
    }

    if(temp == NULL)
    {
        cout << "Value not found\n";
        return;
    }

    Node* newNode = new Node;

    newNode->data = value;
    newNode->next = temp->next;
    newNode->prev = temp;

    if(temp->next != NULL)
    {
        temp->next->prev = newNode;
    }

    temp->next = newNode;
}

void insertEnd(int value)
{
    Node* newNode = new Node;

    newNode->data = value;
    newNode->next = NULL;

    if(head == NULL)
    {
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    Node* temp = head;

    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

void display()
{
    Node* temp = head;

    while(temp != NULL)
    {
        cout << temp->data;

        if(temp->next != NULL)
        {
            cout << " <-> ";
        }

        temp = temp->next;
    }

    cout << endl;
}

int main()
{

    insertEnd(10);
    insertEnd(20);
    insertEnd(30);
    insertEnd(40);
    insertEnd(50);

    cout << "Original List: ";
    display();

    insertStart(5);

    insertAfter(20, 25);

    insertEnd(60);

    cout << "\nFinal Doubly Linked List: ";
    display();

    return 0;
}