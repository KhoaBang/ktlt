#include <stdio.h>

//# Viết hàm get_value
/*****************
# YOUR CODE HERE #
 Nguyễn Sỹ Khoa Bằng 20210094
*****************/
int get_value(int x,int a=2, int b=1,int c=0){// doi so bao gom 3 thanh phan ngam dinh
    return a*x*x+b*x+c;// tra lai gia tri tam thuc bac 2
}

int main(){
    int x;
    scanf("%d", &x);

    int a = 2; //# giá trị mặc định của a
    int b = 1; //# giá trị mặc định của b
    int c = 0; //# giá trị mặc định của c

    //# Nhập 3 số nguyên a, b, c từ bàn phím
    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);
    /*****************
    # YOUR CODE HERE #
    Nguyễn Sỹ Khoa Bằng 20210094 
    *****************/

    printf("a=2, b=1, c=0: %d\n", get_value(x));// in ra gia tri da thuc voi x xac dinh tu nguoi dung
    printf("a=%d, b=1, c=0: %d\n", a, get_value(x, a));// in ra gia tri da thuc voi x va a xac dinh tu nguoi dung
    printf("a=%d, b=%d, c=0: %d\n", a, b, get_value(x, a, b));// in ra gia tri da thuc voi x,a,b xac dinh tu nguoi dung
    printf("a=%d, b=%d, c=%d: %d\n", a, b, c, get_value(x, a, b, c));// in ra gia tri da thuc voi x,a,b,c xac dinh tu nguoi dung

    return 0;
}