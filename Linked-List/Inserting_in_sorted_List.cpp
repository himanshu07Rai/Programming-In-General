#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

void insert(Node **pointerToHead, int x)
{
    Node *p = *pointerToHead, *q = NULL;
    Node *newNode = new Node();
    newNode->data = x;
    newNode->next = NULL;
    if (p == NULL)
    {
        *pointerToHead = newNode;
        return;
    }
    if (x <= p->data)
    {
        newNode->next = *pointerToHead;
        *pointerToHead = newNode;
        return;
    }
    while (p && (p->data) < x)
    {
        q = p;
        p = p->next;
    }
    newNode->next = p;
    q->next = newNode;
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

int main()
{
    Node *head = NULL;
    int x, n = 10, i;
    for (i = 0; i < n; i++)
    {
        cout << "\nEnter a number : ";
        cin >> x;
        insert(&head, x);
        Print(&head);
    }
}