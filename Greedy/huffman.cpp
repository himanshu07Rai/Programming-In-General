#include <bits/stdc++.h>
using namespace std;

struct Item
{
    char ch;
    unsigned freq;
};

struct MinHeapNode
{
    char data;
    unsigned freq;
    MinHeapNode *left, *right;

    MinHeapNode(char data, unsigned freq)
    {
        left = right = NULL;
        this->data = data;
        this->freq = freq;
    }
};

struct compare
{
    bool operator()(MinHeapNode *l, MinHeapNode *r)

    {
        return (l->freq > r->freq);
    }
};

void printCodes(MinHeapNode *root, string str)
{

    if (!root)
        return;

    if (root->data != '$')
        cout << root->data << ": " << str << "\n";

    printCodes(root->left, str + "1");
    printCodes(root->right, str + "0");
}

void HuffmanCodes(vector<Item> &arr, int size)
{
    MinHeapNode *left, *right, *top;

    priority_queue<MinHeapNode *, vector<MinHeapNode *>, compare> minHeap;

    for (auto i : arr)
        minHeap.push(new MinHeapNode(i.ch, i.freq));

    while (minHeap.size() != 1)
    {

        left = minHeap.top();
        minHeap.pop();

        right = minHeap.top();
        minHeap.pop();

        top = new MinHeapNode('$', left->freq + right->freq);

        top->left = left;
        top->right = right;

        minHeap.push(top);
    }

    printCodes(minHeap.top(), "");
}

int main()
{
    int n;
    cin >> n;
    vector<Item> arr(n);
    for (int i = 0; i < n; i++)
    {
        char c;
        int f;
        cin >> c >> f;
        arr[i].ch = c;
        arr[i].freq = f;
    }

    HuffmanCodes(arr, n);

    return 0;
}
