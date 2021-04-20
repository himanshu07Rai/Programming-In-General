#include <bits/stdc++.h>
using namespace std;

/* 
Tower of Hanoi is a mathematical puzzle where we have three rods and n disks. The objective of the puzzle is to move the entire stack to another rod, obeying the following simple rules:
1) Only one disk can be moved at a time.
2) Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack i.e. a disk can only be moved if it is the uppermost disk on a stack.
3) No disk may be placed on top of a smaller disk.

key point is to know which tower is source, which is destination and which is temporary.
Here A is source, B is temporary ans C is destination.

in second function, A is source, B is destination and C is temporary.
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


// void toh(int n, char A, char B, char C){
//     if(n==0)
//         return;
//     toh(n-1,A,C,B);
//     cout<<n<<"["<<A<<" -> "<<B<<"]"<<"\n";
//     toh(n-1,C,B,A);
// }

int main()
{
    char A = 'A', B = 'B', C = 'C';
    TOH(3, A, B, C);
}
