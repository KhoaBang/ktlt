//Viết chương trình yêu cầu nhập giá trị cho 3 biến số nguyên x, y, z kiểu int. Sau đó sử dụng duy
//nhất một con trỏ để cộng giá trị của mỗi biến thêm 100.
# include <stdio.h>
    int main() {
        int x, y, z;
        int *ptr;
        scanf("%d %d %d", &x, &y, &z);// nhap x,y,z
        printf("Here are the values of x, y, and z:\n");
        printf("%d %d %d\n", x, y, z);// in ra x,y,z vua nhap
        /*****************

        # YOUR CODE HERE # Nguyen Sy Khoa Bang 20210094

        *****************/
        ptr=&x;// ptr tro vao bien x
        *ptr=*ptr+100;// tang gia tri cua x lên them 100
        ptr=&y;// ptr tro vao bien y
        *ptr=*ptr+100;// tang gia tri cua y lên them 100
        ptr=&z;// ptr tro vao bien z
        *ptr=*ptr+100;// tang gia tri cua z lên them 100
        printf("Once again, here are the values of x, y, and z:\n");
        printf("%d %d %d\n", x, y, z);// in ra gia tri x,y,z sau khi sua doi
        return 0;
    }