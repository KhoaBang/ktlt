//Viết chương trình in ra địa chỉ của 5 phần tử đầu tiên trong mảng được định nghĩa sau đây:
//int a[7]= {13, -355, 235, 47, 67, 943, 1222};
#include<stdio.h>
int main() {
    printf("NGUYEN SY KHOA BANG - MSSV 20210094\n");
    int a[7]= {13, -355, 235, 47, 67, 943, 1222};
    printf("address of first five elements in memory.\n");
    for (int i=0; i<5;i++) printf("\ta[%d]: %p ",i,&a[i]);
    printf("\n");
}
