#include <bits/stdc++.h>
#define max 10
using namespace std;

void enqueue(int *queue, int &rear, int &front)
{
    if (rear == max - 1)
    {
        cout << "\nQueue Full\n";
        return;
    }
    if (front == -1)
        front++;
    rear++;
    cout << "\nEnter value to be inserted : ";
    cin >> queue[rear];
    return;
}

void dequeue(int *queue, int &rear, int &front)
{
    if (front == -1)
    {
        cout << "\nQueue Empty\n";
        return;
    }
    cout << "\nDeleted " << queue[front];
    for (int i = 0; i < rear; i++)
    {
        queue[i] = queue[i + 1];
    }
    rear--;
    if (rear == -1)
        front--;
    return;
}

void display(int *queue, int &rear, int &front)
{
    if (front == -1)
    {
        cout << "\nQueue Empty\n";
        return;
    }
    cout << "\nCurrently Queue contains : ";
    for (int i = front; i <= rear; i++)
    {
        cout << queue[i] << " ";
    }
    return;
}
int main()
{
    int queue[max], rear = -1, front = -1, ch;
    do
    {
        cout << "\n-----------\nMenu\n1 Insert Element( Enqueue )\n2 Delete Element( Dequeue )\n3 Display\n-----------";
        cout << "\nEnter your choice or any other number to exit: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            enqueue(queue, rear, front);
            break;
        case 2:
            dequeue(queue, rear, front);
            break;
        case 3:
            display(queue, rear, front);
            break;
        }
    } while (ch > 0 && ch < 4);
    return 0;
}