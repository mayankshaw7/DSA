#include <bits/stdc++.h>
using namespace std;

class Complex
{
    int real;
    int img;

public:
    Complex(int r, int i)
    {
        real = r;
        img = i;
    }
    void show()
    {
        cout << real << "+" << img << "i" << endl;
    }
    Complex operator+(Complex &c2) //imp syntax for operator overloading
    {
        int real_Num = this->real + c2.real;
        int img_num = this->img + c2.img;
        Complex c3(real_Num,img_num);
        return c3;
    }
};
int main()
{
    Complex c1(1, 3);
    Complex c2(2, 5);
    c1.show();
    c2.show();

    Complex c3 = c1 + c2;//here operator is overloaded 
    c3.show();
}
