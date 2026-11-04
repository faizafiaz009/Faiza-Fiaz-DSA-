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
    Node* temp = NULL;
    Node* newNode;

    int n, value;

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

    cout << "Enter value to insert at start: ";
    cin >> value;

    newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    head = newNode;

    cout << "Linked List: ";

    temp = head;

    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}