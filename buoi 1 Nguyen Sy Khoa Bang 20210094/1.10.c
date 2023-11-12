#include <stdio.h>
#include <stdlib.h>
int n;
int** makematrix(){ // ham tao ma tran
    int **mt1 = (int **) malloc(n * sizeof(intptr_t));// cap phat bo nho cho mang 2 chieu
    for (int i = 0; i < n; i++) {
        mt1[i] = (int *) malloc(n * sizeof(int));
    }
    return mt1;// tra ve con tro toi mang 2 chieu vua tao
}

int** matrix() { //ham tao ma tran kem nhap lieu
    int **mt1 = makematrix(); // tao ma tran
    for (int i = 0; i < n; i++) { // vong lap lay input
        for (int j = 0; j < n; j++) {
            scanf("%d", &mt1[i][j]);
        }
    }
    return mt1;// tra ve ma tran da co thong tin
}

void inmt(int**mt){ // ham in ra ma tran
    for(int i=0;i<n;i++){ // vong lap in ra ma tran
        for (int j=0;j<n;j++){
            printf("%d ",mt[i][j]);
        }
        printf("\n");
    }
}

int** tich2mt (int** mt1, int** mt2){ //ham tinh tich 2 ma tran
    int** temp = makematrix(); // tao ra ma tran de luu ket qua phep nhan
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            int tich =0;
            for(int k=0;k<n;k++){
                tich=tich+mt1[i][k] * mt2[k][j]; // tinh tich 2 ma tran theo cong thuc
            }
            temp[i][j]=tich;
        }
    }
    return temp; // tra lai ma tran ket qua 
}
int** tong2mt(int**mt1, int** mt2){ // ham tinh tong 2 ma tran
    int** temp = makematrix(); // tao ma tran de luu tong
    for (int i=0; i<n;i++){
        for(int j =0; j<n;j++){
            temp[i][j]= mt1[i][j]+mt2[i][j]; // tinh tung phan tu cua ma tran tong
        }
    }
    return temp; // tra ve ket qua cua ma tran tong
}
int main() {
  printf("Nhap n :");
  scanf("%d",&n);
  int** mt1;
  int**mt2;
  mt1=matrix();
  mt2=matrix();
  printf("\n");
  printf("Tong 2 ma tran la :\n");
  inmt(tong2mt(mt1,mt2));
  printf("\n");
  printf("Tich 2 ma tran la :\n");
  inmt(tich2mt(mt1,mt2));
}
