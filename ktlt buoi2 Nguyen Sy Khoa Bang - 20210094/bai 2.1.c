#include<math.h>
#include<stdio.h>
float get_hypotenuse(float x, float y) {
    /*****************
    # YOUR CODE HERE #
    Nguyễn Sỹ Khoa Bằng 20210094
    *****************/
    return (float)sqrt(x*x+y*y);// tra lai gia tri canh huyen
}
int main(){
        float a,b;// khai bao 2 bien a,b
        scanf("%f",&a);// nhap a
        scanf("%f",&b);// nhap b
        printf("z = %.2f",get_hypotenuse(a,b));// in ra z la gia tri canh huyen
        return 0;
}