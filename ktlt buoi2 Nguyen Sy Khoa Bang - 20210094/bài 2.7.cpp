#include <iostream>
using namespace std;

//# viết hàm arr_sum
/*****************
# YOUR CODE HERE #
 Nguyen Sy Khoa Bang 20210094
*****************/
template <typename T>
auto arr_sum(T a[],int x, T b[], int y){// ham arr voi template t
    T sum =0;
    for (int i =0; i<x;i++){// tong cac phan tu o mang a
        sum=sum +a[i];
    }
    for (int i =0; i<y;i++){// tong cac phan tu o mang b
        sum =sum + b[i];
    }

    return sum;// tra lai gia tri tong
}
int main() {
    int val;// nhap val
    cin >> val;

    {
        int a[] = {3, 2, 0, val};
        int b[] = {5, 6, 1, 2, 7};
        cout << arr_sum(a, 4, b, 5) << endl;// in ra ket qua cua ham arr_sum voi T la int
    }
    {
        double a[] = {3.0, 2, 0, val * 1.0};
        double b[] = {5, 6.1, 1, 2.3, 7};
        cout << arr_sum(a, 4, b, 5) << endl;// in ra ket qua cua ham arr_sum voi T la double
    }

    return 0;
}