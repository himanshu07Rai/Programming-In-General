#include <bits/stdc++.h>
using namespace std;

/* 
Tower of Hanoi is a mathematical puzzle where we have three rods and n disks. The objective of the puzzle is to move the entire stack to another rod, obeying the following simple rules:
1) Only one disk can be moved at a time.
2) Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack i.e. a disk can only be moved if it is the uppermost disk on a stack.
3) No disk may be placed on top of a smaller disk.
*/

void TOH(int n, char A, char B, char C)
{
    if (n > 0)
    {
        TOH(n - 1, A, C, B);
        cout << "from " << A << " to " << C << endl;
        TOH(n - 1, B, A, C);
    }
}

int main()
{
    char A = 'A', B = 'B', C = 'C';
    TOH(3, A, B, C);
}