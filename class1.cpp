#include <bits/stdc++.h>
using namespace std;
class Complex
{
    int v1, v2;

public:
    Complex(int v1 = 2, int v2 = 5)
    {
        this->v1 = v1;
        this->v2 = v2;
    }
    Complex addObjects(Complex c2)
    {
        Complex temp;
        temp.v1 = v1 + c2.v1;
        temp.v2 = v2 + c2.v2;
        return temp;
    }
    // void getData()
    // {
    //     cout << this->v1 << " + i" << this->v2;
    // }
    int getV1()
    {
        return this->v1;
    }
    int getV2()
    {
        return this->v2;
    }
};
int main()
{
    Complex c1(2, 3);
    Complex c2(3, 4);
    Complex t = c1.addObjects(c2);
    cout << "C1 object : " << c1.getV1() << " + i" << c1.getV2();
    cout << "\nC2 object : " << c2.getV1() << " + i" << c2.getV2();
    cout << "\nAfter addition : " << t.getV1() << " + i" << t.getV2();
}