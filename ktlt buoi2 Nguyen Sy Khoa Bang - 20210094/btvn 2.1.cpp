#include<iostream>
#include <numeric>
using namespace std;
// Nguyen Sy Khoa Bang 20210094
int *f1,*f2;
int n,m;
void input(){// nhap 2 da thuc
    cin>> n;
    f1=new int[n];
    for(int i=0; i<=n;i++){
        cin>>f1[i];
    }
    cin>>m;
    f2= new int[m];
    for (int i=0; i<=m; i++){
        cin>>f2[i];
    }
}

void product(int*&func1, int*&func2, int ketqua[]){// tich 2 da thuc, luu ket qua vao mang ketqua[]
    for (int i =0; i<=n;i++){
        for (int j =0; j<=m;j++){
            ketqua[n-i+m-j]+=func1[i]*func2[j];
        }
    }
}
void output(int ketqua[]) {// in ra ketqua []
    int g=0;
    int t = m + n;
    for (int i = 0; i <= t; i++) {
        g= g xor ketqua[i];
    }
    cout<< g;
}

int main(){
    int ketqua[10000];
    input();
    product(f1,f2,ketqua);
    output(ketqua);
    return 0;
}