#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next; //struct Node *next;
};

Node *head;

/*this head is not a node with data and address field. This only contains the Address of list of of the first node.*/

void insert(int x)
{
    Node *temp = new Node(); //Node *temp = (Node *)malloc(sizeof(struct Node));
    temp->data = x;
    Node *i = head;
    if (i == NULL)
    {
        head = temp;
        temp->next = NULL;
    }
    else
    {
        while (i->next != NULL)
        {
            i = i->next;
        }
        i->next = temp; //insert at end
        temp->next = NULL;
    }
}

void Delete(int n)
{
    Node *temp1 = head;
    if (n == 1)
    {
        head = temp1->next;
        delete temp1;
        return;
    }
    int i;
    for (i = 0; i < n - 2; i++)
        temp1 = temp1->next;
    Node *temp2 = temp1->next;
    temp1->next = temp2->next;
    delete temp2;
}

void Print()
{
    Node *temp = head;
    cout << "List is : ";
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}
int main()
{
    head = NULL; //empty list
    insert(2);
    insert(4);
    insert(6);
    insert(8);
    insert(10);
    insert(12);
    insert(14);
    Print();
    int n;
    cout << "\nEnter a position : ";
    cin >> n;
    Delete(n);
    Print();
}