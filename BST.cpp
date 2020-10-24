/* Tree traversal : process of visiting (reading/processing data in the node) each node in the tree exactly once in some order */

#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *GetNewNode(int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node *Insert(Node *rootPtr, int data)
{
    if (rootPtr == NULL)
        rootPtr = GetNewNode(data);
    else if (data <= rootPtr->data)
        rootPtr->left = Insert(rootPtr->left, data);
    else
        rootPtr->right = Insert(rootPtr->right, data);

    return rootPtr; //returns the address of newly created Node
}

bool Search(Node *rootPtr, int data)
{
    if (rootPtr == NULL)
        return false;
    else if (data == rootPtr->data)
        return true;
    else if (data <= rootPtr->data)
        return Search(rootPtr->left, data);
    else
        return Search(rootPtr->right, data);
}

void FindMin(Node *rootPtr)
{
    if (rootPtr == NULL)
        cout << "\nMin : (ERROR)Tree is empty!";
    else if (rootPtr->left == NULL)
        cout << "\nMin = " << rootPtr->data;
    else
        FindMin(rootPtr->left);
}
void FindMax(Node *rootPtr)
{
    if (rootPtr == NULL)
        cout << "\nMax : (ERROR)Tree is empty!";
    else if (rootPtr->right == NULL)
        cout << "\nMax = " << rootPtr->data;
    else
        FindMax(rootPtr->right);
}
int FindHeight(Node *rootPtr)
{
    if (rootPtr == NULL)
        return 0;
    return max(FindHeight(rootPtr->left), FindHeight(rootPtr->right)) + 1;
}
int main()
{
    Node *rootPtr;
    rootPtr = NULL; //empty tree
    cout << "\nEnter data values : \n";
    int i = 8, a;
    while (i--)
    {
        cin >> a;
        rootPtr = Insert(rootPtr, a);
    }
    cout << "\nEnter a number to search : ";
    cin >> a;
    if (Search(rootPtr, a))
        cout << "Found\n";
    else
        cout << "Not Found\n";
    FindMin(rootPtr);
    FindMax(rootPtr);
    cout << "\nHeight/Max Depth : " << FindHeight(rootPtr);

    return 0;
}