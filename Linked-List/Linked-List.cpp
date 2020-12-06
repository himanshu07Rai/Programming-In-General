#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

void insertBeginning(Node **pointerToHead, int x)
{
    Node *temp = new Node();
    temp->data = x;
    temp->next = *pointerToHead; //insert at beginning
    *pointerToHead = temp;
}

void insertEnd(Node **pointerToHead, int x)
{
    Node *temp = new Node();
    temp->data = x;
    temp->next = NULL;
    Node *last = *pointerToHead;
    if (last == NULL)
    {
        *pointerToHead = temp;
        return;
    }
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = temp;
}

void insertPos(Node **pointerToHead, int x, int pos)
{
    Node *temp = new Node();
    temp->data = x;
    Node *p = *pointerToHead;
    Node *q = NULL;
    for (int i = 1; i <= pos - 2; i++)
    {
        p = p->next;
    }
    temp->next = p->next;
    p->next = temp;
}

void Count(Node **pointerToHead)
{
    Node *p = *pointerToHead;
    int count = 0;
    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    cout << "\nNo. of Nodes : " << count << "\n";
}

void Print(Node **pointerToHead)
{
    Node *temp = *pointerToHead;
    if (temp == NULL)
    {
        cout << "List is Empty!";
        return;
    }
    cout << "List is : ";
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void sumOfAllElements(Node **head)
{
    Node *p = *head;
    long long sum = 0;
    while (p != NULL)
    {
        sum += p->data;
        p = p->next;
    }
    cout << "\nSum of all Elements : " << sum << "\n";
}

void Max(Node **pointerToHead)
{
    Node *p = *pointerToHead;
    int max = 0;
    while (p != NULL)
    {
        if (p->data > max)
            max = p->data;
        p = p->next;
    }
    cout << "\nMax Elements : " << max << "\n";
}

void Search(Node **pointerToHead, int x) //can't use Binary search
{
    Node *p = *pointerToHead;
    while (p != NULL)
    {
        if (p->data == x)
        {
            cout << "Element found at " << p;
            return;
        }
        p = p->next;
    }
    cout << "\nElement not found! \n";
}

void Delete(Node **pointerToHead, int n)
{
    Node *temp1 = *pointerToHead;
    if (n == 1)
    {
        *pointerToHead = temp1->next;
        delete temp1;
        return;
    }
    Node *temp2 = NULL;
    int i;
    for (i = 0; i < n - 1 && temp1; i++)
    {
        temp2 = temp1;
        temp1 = temp1->next;
    }
    temp2->next = temp1->next;
    temp1->next = NULL;
    delete temp1;
}

int main()
{
    Node *head = NULL;
    int ch, val;
    do
    {
        cout << endl
             << endl;
        cout << "1) Insert At End" << endl;
        cout << "2) Insert At the Beginning" << endl;
        cout << "3) Insert At a given position" << endl;
        cout << "4) Counting no. of Nodes" << endl;
        cout << "5) Printing List" << endl;
        cout << "6) Print sum of all elements" << endl;
        cout << "7) Find maximum" << endl;
        cout << "8) Search Element" << endl;
        cout << "9) Delete Node" << endl;
        cout << "10) Exit" << endl;
        cout << "Enter choice: " << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            cout << "Enter value : ";
            cin >> val;
            insertEnd(&head, val);
            break;
        }
        case 2:
        {
            cout << "Enter value : ";
            cin >> val;
            insertBeginning(&head, val);
            break;
        }
        case 3:
        {
            int pos;
            cout << "Enter value : ";
            cin >> val;
            cout << "\nEnter position : ";
            cin >> pos;
            insertPos(&head, val, pos);
            break;
        }
        case 4:
        {
            Count(&head);
            break;
        }
        case 5:
        {
            Print(&head);
            break;
        }
        case 6:
        {
            sumOfAllElements(&head);
            break;
        }
        case 7:
        {
            Max(&head);
            break;
        }
        case 8:
        {
            cout << "\nEnter element to be searched for : ";
            cin >> val;
            Search(&head, val);
            break;
        }
        case 9:
        {
            int pos;
            cout << "\nEnter a position : ";
            cin >> pos;
            Delete(&head, pos);
            Print(&head);
            break;
        }
        case 10:
        {
            cout << "Exit...";
            break;
        }
        default:
        {
            cout << "Invalid Choice" << endl;
        }
        }
    } while (ch != 10);
}