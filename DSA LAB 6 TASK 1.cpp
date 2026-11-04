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


void deleteAtStart()
{
    if(head == NULL)
    {
        cout << "List is empty\n";
        return;
    }

    Node* temp = head;
    head = head->next;

    delete temp;
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

    deleteAtStart();

    cout << "After first deletion: ";
    display();

    deleteAtStart();

    cout << "After second deletion: ";
    display();

    return 0;
}