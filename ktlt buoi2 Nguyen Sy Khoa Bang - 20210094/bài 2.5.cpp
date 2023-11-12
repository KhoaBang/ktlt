#include <iostream>
#include <ostream>
#include <math.h>
#include <iomanip>

using namespace std;

typedef struct Complex {// tao struct Complex bieu dien so phuc
    double real;
    double imag;
}Complex;

Complex operator + (Complex a, Complex b) {// da nang hoa toan tu +
    /*****************
    # YOUR CODE HERE #
     Nguyễn Sỹ Khoa Bằng 20210094
    *****************/
    Complex c;
    c.real = a.real+b.real;
    c.imag = a.imag +b.imag;
    return c;
}

Complex operator - (Complex a, Complex b) {// da nang hoa toan tu -
    /*****************
    # YOUR CODE HERE #
     Nguyễn Sỹ Khoa Bằng 20210094
    *****************/
    Complex c;
    c.real = a.real-b.real;
    c.imag = a.imag -b.imag;
    return c;
}

Complex operator * (Complex a, Complex b) {// da nang hoa toan tu *
    /*****************
    # YOUR CODE HERE #
     Nguyễn Sỹ Khoa Bằng 20210094
    *****************/
    Complex c;
    c.real = a.real*b.real-a.imag*b.imag;
    c.imag = a.imag*b.real +b.imag*a.real;
    return c;
}

Complex operator / (Complex a, Complex b) {// da nang hoa toan tu /
    /*****************
    # YOUR CODE HERE #
     Nguyễn Sỹ Khoa Bằng 20210094
    *****************/
    Complex c;
    c.real = (a.real*b.real+a.imag*b.imag)/(b.real*b.real+b.imag*b.imag);
    c.imag = (a.imag*b.real -b.imag*a.real)/(b.real*b.real+b.imag*b.imag);
    return c;
}

ostream& operator << (ostream& out, const Complex &a) {
    out << '(' << std::setprecision(2) << a.real << (a.imag >= 0 ? '+' : '-') << std::setprecision(2) << fabs(a.imag) << 'i' << ')';
    return out;
}

int main() {
    double real_a, real_b, img_a, img_b;
    cin >> real_a >> img_a;
    cin >> real_b >> img_b;

    Complex a{real_a, img_a};
    Complex b{real_b, img_b};

    cout << a << " + " << b << " = " << a + b << endl;
    cout << a << " - " << b << " = " << a - b << endl;
    cout << a << " * " << b << " = " << a * b << endl;
    cout << a << " / " << b << " = " << a / b << endl;

    return 0;
}