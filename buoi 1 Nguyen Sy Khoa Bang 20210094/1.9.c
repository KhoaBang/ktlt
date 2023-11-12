// bai 1.9
#include <stdio.h>
#include <stdlib.h>
int main() {
    printf("NGUYEN SY KHOA BANG - MSSV 20210094\n");
    int n;
    printf("Nhap so luong cua day: ");
    scanf("%d",&n);
    printf("Nhap day: ");
    int* arr = (int*)malloc(n*sizeof(int));// cap phat dong cho mang
    for (int i=0;i<n;i++){ // vong lap lay du lieu
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n;i++){ // vong lap xu ly du lieu
        for(int j=i;j<n;j++){
            for(int k=i;k<=j;k++){
                printf("%d ",arr[k]);
            }
            printf("\n");
        }
    }

}
