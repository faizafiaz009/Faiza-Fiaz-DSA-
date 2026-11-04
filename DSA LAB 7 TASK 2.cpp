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
        cout << "Product not found\n";
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

void deleteStart()
{
    if(head == NULL)
    {
        return;
    }

    Node* temp = head;

    head = head->next;

    if(head != NULL)
    {
        head->prev = NULL;
    }

    delete temp;
}

void deleteByValue(int value)
{
    Node* temp = head;

    while(temp != NULL && temp->data != value)
    {
        temp = temp->next;
    }

    if(temp == NULL)
    {
        cout << "Product not found\n";
        return;
    }

    if(temp == head)
    {
        head = temp->next;

        if(head != NULL)
        {
            head->prev = NULL;
        }
    }
    else
    {
        temp->prev->next = temp->next;

        if(temp->next != NULL)
        {
            temp->next->prev = temp->prev;
        }
    }

    delete temp;
}
void deleteEnd()
{
    if(head == NULL)
    {
        return;
    }

    Node* temp = head;

    if(head->next == NULL)
    {
        delete head;
        head = NULL;
        return;
    }

    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->prev->next = NULL;

    delete temp;
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

    insertEnd(101);
    insertEnd(102);
    insertEnd(103);
    insertEnd(104);
    insertEnd(105);

    cout << "Original List: ";
    display();

    insertStart(100);

    insertAfter(103, 1035);

    insertEnd(106);

    cout << "\nAfter Insertion: ";
    display();

    deleteStart();

    cout << "\nAfter Deleting First Product: ";
    display();

    deleteByValue(104);

    cout << "\nAfter Deleting Product 104: ";
    display();

    deleteEnd();

    cout << "\nAfter Deleting Last Product: ";
    display();

    return 0;
}