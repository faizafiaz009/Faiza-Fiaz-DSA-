#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
};

int main()
{
    Node* head = NULL;
    Node* temp;
    Node* prev = NULL;
    Node* newNode;

    int n, value, key;

    cout << "Enter number of nodes: ";
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        newNode = new Node;

        cout << "Enter value: ";
        cin >> newNode->data;

        newNode->next = NULL;

        if(head == NULL)
        {
            head = newNode;
        }
        else
        {
            temp = head;

            while(temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newNode;
        }
    }

    cout << "Enter existing value: ";
    cin >> key;

    cout << "Enter new value: ";
    cin >> value;

    temp = head;

    while(temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL)
    {
        cout << "Value not found!";
    }
    else
    {
        newNode = new Node;
        newNode->data = value;

        newNode->next = temp;

        if(prev == NULL)
        {
            head = newNode;
        }
        else
        {
            prev->next = newNode;
        }
    }

    cout << "\nLinked List: ";

    temp = head;

    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}