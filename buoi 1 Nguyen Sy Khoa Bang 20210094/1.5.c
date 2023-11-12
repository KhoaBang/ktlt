//Viết hàm trả về con trỏ trỏ tới giá trị lớn nhất của một mảng các số double. Nếu mảng rỗng hãy trả
//về NULL.
# include <stdio.h>
double* maximum(double* a, int size){

    double *max;// khoi tao con tro max
    max = a;// cho max tro vao mang a
    if (a==NULL) return NULL;// neu mang a rong thi tra ve NULL
    /*****************

    # YOUR CODE HERE # Nguyen Sy Khoa Bang 20210094

    *****************/
        if (size ==0) return NULL;// neu mang a khong co phan tu thi tra ve NULL
        double temp=0;// tao bien tam thoi = 0
        for (int i =0;i<size;i++) {// tao vong lap xet toan bo cac phan tu cua mang a
            if (temp < a[i]) {// neu phan tu thu i trong mang a nho hon bien temp
                temp=a[i];// thi cap nhat bien temp voi gia tri a[i]
                max = &a[i];// con tro max tro vao a[i]
            }
        }
    return max;// tra ve con tro max
