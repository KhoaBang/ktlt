//Viết chương trình nhập vào một mảng các số nguyên với số lượng các phần tử nhập từ bàn phím.
//Sau đó sắp xếp mảng theo thứ tự tăng dần. Hiển thị danh sách mảng trước và sau khi sắp xếp.
//Yêu cầu chỉ sử dụng con trỏ để truy cập mảng, không truy cập theo index mảng.
#include <stdio.h>
#include <stdlib.h>
    int *a;
    int n, tmp;
    void swap(int* x, int* y)// ham hoan doi 2 phan tu
    {
        int temp = *x;
        *x = *y;
        *y = temp;
    }
    int main(){
        printf("Enter the number of elements: ");
        scanf("%d", &n);
//#Allocate memory
/*****************
# YOUR CODE HERE # Nguyen Sy Khoa Bang 20210094
*****************/
        int *a=(int*)malloc(n*sizeof(int));// cap phat dong vung nho co n phan tu kieu int
        for(int i = 0; i < n; i++)// vong lap input
            scanf("%d", a + i);
        printf("The input array is: \n");// in ra input vua nhap
        for(int i = 0; i < n; i++)
            printf("%d ", *(a + i));
        printf("\n");
//#Sort array
/*****************
# YOUR CODE HERE #
*****************/
        for (int i=0;i<n;i++) {// vong lap lon
            for (int j = i; j < n; j++) {// vong lap nho
                if (*(a + i) > *(a + j)) {// neu a[j] co gia tri nho hon a[i] thi doi cho
                    swap((a + i), (a + j));
                }
            }
        }
        printf("The sorted array is: \n");// in ra mang vua sort
        for(int i = 0; i < n; i++)
            printf("%d ", *(a + i));
        printf("\n");
        free (a);
        return 0;
    }