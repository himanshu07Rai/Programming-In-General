#include <bits/stdc++.h>
#define max 15
using namespace std;

int push(int *stack, int top)
{
    if (top == max - 1)
    {
        cout << "\nStack Full\n";
        return top;
    }
    top++;
    cout << "\nEnter value to be pushed : ";
    cin >> stack[top];
    return top;
}

int pop(int *stack, int top)
{
    if (top == -1)
    {
        cout << "\nStack Empty\n";
        return top;
    }
    cout << "\nDeleted " << stack[top];
    top--;
    return top;
}

void peek(int *stack, int top)
{
    if (top == -1)
    {
        cout << "\nStack Empty\n";
        return;
    }
    cout << "\n"
         << "Element on top : " << stack[top] << "\n";
    return;
}

void display(int *stack, int top)
{
    if (top == -1)
    {
        cout << "\nStack Empty\n";
        return;
    }
    cout << "\nCurrently Stack contains : ";
    for (int i = top; i >= 0; i--)
    {
        cout << "\n"
             << stack[i];
    }
    return;
}
int main()
{
    int stack[max], top = -1, ch;
    do
    {
        cout << "\n-----------\nMenu\n1 Push\n2 Pop\n3 Display\n4 Peek\n-----------";
        cout << "\nEnter your choice or any other number to exit: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            top = push(stack, top);
            break;
        case 2:
            top = pop(stack, top);
            break;
        case 3:
            display(stack, top);
            break;
        case 4:
            peek(stack, top);
            break;
        }
    } while (ch > 0 && ch < 5);
    return 0;
}