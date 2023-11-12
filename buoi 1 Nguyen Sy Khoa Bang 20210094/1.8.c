#include <stdio.h>
#include <stdlib.h>
/*****************
# YOUR CODE HERE # Nguyen Sy Khoa Bang 20210094
*****************/
void allocate_mem(int ***mt, int m, int n){// ham cap phat dong
    *mt = (int**)malloc(m*sizeof(int));// cap phat dong mang 2 chieu
    for (int i=0;i<m;i++){
        (*mt)[i]=(int*)malloc(n*sizeof(int));
    }
}

void input(int **mt, int m, int n){// nhap input
    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            printf("mt[%d][%d] = ",i,j);
            scanf("%d",&mt[i][j]);
        }
    }
}

void output(int **mt, int m, int n){// xuat output
    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            printf("%d ",mt[i][j]);
        }
        printf("\n");
    }
}
int process(int **mt, int m, int n){// ham xu ly
    int tong = 0;
    for (int i=0;i<m;i++){// tao vong lap de xet tung phan tu cua mang 2 chieu
        for (int j=0;j<n;j++){
            if(mt[i][j]%2==0)// neu so dang xet la so chan
                tong+=mt[i][j];// cap nhat tong
        }
    }
    return tong;// tra ve tong
}
void free_mem(int **mt, int m, int n){
    for (int i=0;i<m;i++){
        free(mt[i]);// tra lai bo nho da cap phat
    }
    free (mt);
}

int main() {
    int m, n, **mt;
    printf("Enter m, n = ");
    scanf("%d%d", &m, &n);
    allocate_mem(&mt, m, n);
    input(mt, m, n);
    output(mt, m, n);
    printf("The sum of all even elements is %d", process(mt, m, n));
    free_mem(mt, m, n);
    return 0;
}