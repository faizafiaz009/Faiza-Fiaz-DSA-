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
    Node* n1 = new Node;
    Node* n2 = new Node;
    Node* n3 = new Node;

    n1->data = 90;
    n2->data = 30;
    n3->data = 10;

    n1->next = n2;
    n2->next = n3;
    n3->next = NULL;

    Node* temp = n1;

    cout << "Linked List: ";

    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}