#include <stdio.h>

void rotate(int &x, int &y, int &z) {// chuyen tham chieu trong c++
/*****************
# YOUR CODE HERE #
Nguyễn Sỹ Khoa Bằng 20210094
*****************/
int temp;// tao gia tri tam thoi
temp=x;// lưu x vao gia tri tam thoi
x=y;// gan vong tron
y=z;
z=temp;
}

int main() {
    int x, y, z;
    //# Nhập 3 số nguyên
    /*****************
    # YOUR CODE HERE #
    Nguyễn Sỹ Khoa Bằng 20210094
    *****************/
    scanf("%d",&x);// nhap x,y,z
    scanf("%d",&y);
    scanf("%d",&z);
    printf("Before: %d, %d, %d\n", x, y, z);// in ra gia tri x,y,z truoc khi goi ham
    rotate(x, y, z);// goi ham
    printf("After: %d, %d, %d\n", x, y, z);// in ra gia tri sau khi goi ham

    return 0;
}