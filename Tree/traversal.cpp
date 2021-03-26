#include <bits/stdc++.h>
#define nl "\n"
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

Node *FindMin(Node *root)
{
    if (root == NULL || root->left == NULL)
        return root;
    return FindMin(root->left);
}

Node *Delete(Node *rootPtr, char c)
{
    if (rootPtr == NULL)
        return rootPtr;
    else if (c < rootPtr->data)
        rootPtr->left = Delete(rootPtr->left, c);
    else if (c > rootPtr->data)
        rootPtr->right = Delete(rootPtr->right, c);
    else
    {
        if (rootPtr->left == NULL && rootPtr->right == NULL)
        {
            delete rootPtr;
            rootPtr = NULL;
        }
        else if (rootPtr->left == NULL)
        {
            Node *temp = rootPtr;
            rootPtr = rootPtr->right;
            delete temp;
        }
        else if (rootPtr->right == NULL)
        {
            Node *temp = rootPtr;
            rootPtr = rootPtr->left;
            delete temp;
        }
        else
        {
            Node *temp = FindMin(rootPtr->right);
            rootPtr->data = temp->data;
            rootPtr->right = Delete(rootPtr->right, temp->data);
        }
    }
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
void levelorder(Node *rootPtr) {
	if(rootPtr == NULL) return;
	queue<Node*> Q;
	Q.push(rootPtr);  
	//while there is at least one discovered node
	while(!Q.empty()) {
		Node* current = Q.front();
		Q.pop(); // removing the element at front
		cout<<current->data<<" ";
		if(current->left != NULL) Q.push(current->left);
		if(current->right != NULL) Q.push(current->right);
	}
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
    cout << rootPtr->data << nl << "Before deleting:" << nl;
    preorder(rootPtr);
    cout << nl;
    inorder(rootPtr);
    cout << nl;
    postorder(rootPtr);
    cout << nl;
    levelorder(rootPtr);
    a = 'D';
    rootPtr = Delete(rootPtr, a);
    cout << nl << "After deleting" << nl;
    preorder(rootPtr);
    cout << nl;
    inorder(rootPtr);
    cout << nl;
    postorder(rootPtr);
    cout << nl;
    levelorder(rootPtr);
}