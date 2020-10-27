#include <bits/stdc++.h>
using namespace std;
struct Node
{
    char data;
    Node *left;
    Node *right;
};

Node *GetNewNode(char data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node *Insert(Node *rootPtr, char data)
{
    if (rootPtr == NULL)
        rootPtr = GetNewNode(data);
    else if (data <= rootPtr->data)
        rootPtr->left = Insert(rootPtr->left, data);
    else
        rootPtr->right = Insert(rootPtr->right, data);

    return rootPtr;
}

void preorder(Node *rootPtr)
{
    if (rootPtr == NULL)
        return;
    cout << rootPtr->data << " ";
    preorder(rootPtr->left);
    preorder(rootPtr->right);
}
void inorder(Node *rootPtr)
{
    if (rootPtr == NULL)
        return;
    inorder(rootPtr->left);
    cout << rootPtr->data << " ";
    inorder(rootPtr->right);
}
void postorder(Node *rootPtr)
{
    if (rootPtr == NULL)
        return;
    postorder(rootPtr->left);
    postorder(rootPtr->right);
    cout << rootPtr->data << " ";
}

int main()
{
    Node *rootPtr;
    rootPtr = NULL; //empty tree
    cout << "\nEnter data values : \n";
    int i = 11;
    char a;
    while (i--)
    {
        cin >> a;
        rootPtr = Insert(rootPtr, a);
    }
    cout << rootPtr->data << endl;
    preorder(rootPtr);
    cout << "\n";
    inorder(rootPtr);
    cout << "\n";
    postorder(rootPtr);
}