#include <stdio.h>

int cube(int x) { // ham nhan vao doi so kieu int, tra lai gia tri kieu int
    //# trả về lập phương của x
    /*****************
    # YOUR CODE HERE #
     Nguyễn Sỹ Khoa Bằng 20210094
    *****************/
    return x*x*x;
}

//# viết hàm tính lập phương của một số kiểu double
double cube(double x) {// ham nhan vao doi so kieu double, tra lai gia tri double
    //# trả về lập phương của x
    /*****************
    # YOUR CODE HERE #
     Nguyễn Sỹ Khoa Bằng 20210094
    *****************/
    return x*x*x;
}

int main() {
    int n;
    double f;
    scanf("%d %lf", &n, &f);// nhap 2 so

    printf("Int: %d\n", cube(n));// in ra gia tri nguyen
    printf("Double: %.2lf\n", cube(f));// in ra gia tri double

    return 0;
}