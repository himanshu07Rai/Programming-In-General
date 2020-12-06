#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next; //struct Node *next;
};
/*GLOBAL
struct Node *head;
*/

/*this head is not a node with data and address field. This only contains the Address of list of of the first node.*/

/*GLOBAL
void insert(int x)
{
    Node *temp = new Node(); //Node *temp = (Node *)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = head; //insert at beginning
    head = temp;
}
*/

void insert(Node **pointerToHead, int x)
{
    Node *temp = new Node(); //Node *temp = (Node *)malloc(sizeof(struct Node));
    temp->data = x;
    Node *i = *pointerToHead;
    if (i == NULL)
    {
        *pointerToHead = temp;
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

void Print(Node **pointerToHead)
{
    Node *temp = *pointerToHead;
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
    /*GLOBAL
    head = NULL; //empty list
    */
    Node *head = NULL;
    int x, n = 10, i;
    for (i = 0; i < n; i++)
    {
        cout << "\nEnter a number : ";
        cin >> x;

        /*
        GLOBAL
        insert( x);
        Print();
        */

        insert(&head, x);
        Print(&head);
    }
}