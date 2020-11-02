#include <bits/stdc++.h>
using namespace std;
class Student
{
private:
    static int count;

protected:
    static string universityName;

public:
    static int noOfDepts;
    static int getCount()
    {
        return count;
    }
    static string getUni()
    {
        return universityName;
    }
};

class Count
{
private:
    int x;

public:
    friend void setX(Count &, int);
    Count(int x = 5)
    {
        this->x = x;
    }
    void print()
    {
        cout << "x=" << x << endl;
    }
};

void setX(Count &counter, int val)
{
    counter.x = val;
}

int Student ::noOfDepts = 10;
int Student ::count;
string Student ::universityName;

int main()
{
    // cout << Student::noOfDepts;
    // cout << "\nCount : " << Student::getCount;
    // cout << "\nUniversity : " << Student::getUni;
    Count counter;
    counter.print();
    setX(counter, 10);
    counter.print();
}