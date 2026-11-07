#include <iostream>
using namespace std;

#define SIZE 4

int queue[SIZE];
int front = -1;
int rear = -1;
int count = 0;

void enqueue(int value)
{
    if (count == SIZE)
    {
        cout << "Printer queue is full!" << endl;
        return;
    }

    if (count == 0)
    {
        front = 0;
    }

    rear = (rear + 1) % SIZE;
    queue[rear] = value;
    count++;

    cout << value << " inserted." << endl;
}

void dequeue()
{
    if (count == 0)
    {
        cout << "Printer queue is empty!" << endl;
        return;
    }

    cout << "Printed job: " << queue[front] << endl;

    front = (front + 1) % SIZE;
    count--;

    if (count == 0)
    {
        front = -1;
        rear = -1;
    }
}

void display()
{
    if (count == 0)
    {
        cout << "Queue is empty!" << endl;
        return;
    }

    cout << "Printer jobs: ";

    for (int i = 0; i < count; i++)
    {
        int index = (front + i) % SIZE;
        cout << queue[index] << " ";
    }

    cout << endl;
}

int main()
{
    enqueue(101);
    enqueue(102);
    enqueue(103);
    enqueue(104);

    enqueue(105);

    dequeue();
    dequeue();

    enqueue(105);
    enqueue(106);

    display();

    cout << "Front: " << front << endl;
    cout << "Rear: " << rear << endl;
    cout << "Count: " << count << endl;

    return 0;
}
