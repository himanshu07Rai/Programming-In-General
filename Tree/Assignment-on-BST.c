#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *GetNewNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
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

    return rootPtr;
}

int totalNodes(Node *rootPtr)
{
    if (rootPtr == NULL)
        return 0;
    if (rootPtr->left == NULL && rootPtr->right == NULL)
        return 1;
    return totalNodes(rootPtr->left) + totalNodes(rootPtr->right) + 1;
}
int totalLeafNodes(Node *rootPtr)
{
    if (rootPtr == NULL)
        return 0;
    if (rootPtr->left == NULL && rootPtr->right == NULL)
        return 1;
    return totalLeafNodes(rootPtr->left) + totalLeafNodes(rootPtr->right);
}
int nodeLeftChild(Node *rootPtr)
{
    if (rootPtr == NULL)
        return 0;
    if (rootPtr->left == NULL && rootPtr->right == NULL)
        return 0;
    if (rootPtr->left != NULL && rootPtr->right == NULL)
        return 1 + nodeLeftChild(rootPtr->left);
    else
        return nodeLeftChild(rootPtr->right) + nodeLeftChild(rootPtr->left);
}
int nodeRightChild(Node *rootPtr)
{
    if (rootPtr == NULL)
        return 0;
    if (rootPtr->left == NULL && rootPtr->right == NULL)
        return 0;
    if (rootPtr->left == NULL && rootPtr->right != NULL)
        return 1 + nodeRightChild(rootPtr->right);
    else
        return nodeRightChild(rootPtr->right) + nodeRightChild(rootPtr->left);
}
int main()
{
    Node *rootPtr;
    rootPtr = NULL;
    rootPtr = Insert(rootPtr, 300);
    rootPtr = Insert(rootPtr, 200);
    rootPtr = Insert(rootPtr, 450);
    rootPtr = Insert(rootPtr, 150);
    rootPtr = Insert(rootPtr, 600);
    rootPtr = Insert(rootPtr, 500);

    printf("\nTotal nodes : %d", totalNodes(rootPtr));
    printf("\nTotal Leaf nodes : %d", totalLeafNodes(rootPtr));
    printf("\nTotal nodes with only left child : %d", nodeLeftChild(rootPtr));
    printf("\nTotal nodes with only right child : %d", nodeRightChild(rootPtr));
    printf("\nTotal nodes having information greater than root : %d", totalNodes(rootPtr->right));
    return 0;
}