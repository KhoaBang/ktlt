#include<iostream>
using namespace std;
// Nguyen Sy Khoa Bang 20210094
struct bigNum {
    char sign;
    char num[201];// do tich 2 so co 100 chu so dai 200 chu so (de luu tich)
};

// nhap lieu va tien xu ly du lieu
void input(bigNum &num1, bigNum &num2){
    string tmp;
    cin >> tmp;
    num1.sign = tmp[0];
    int lens1 = tmp.length() - 1;
    for(int i=0; i<lens1; i++){
        num1.num[200-lens1+i+1] = tmp[i+1];// copy từ nhap lieu vào num tu cuoi len
    }
    for(int i=0; i<200-lens1+1; i++) num1.num[i] = '0';// dien nhung so con lai la ky tu 0

    cin >> tmp;
    num2.sign = tmp[0];
    int lens2 = tmp.length() - 1;
    for(int i=0; i<lens2; i++){
        num2.num[200-lens2+i+1] = tmp[i+1];
    }
    for(int i=0; i<200-lens2+1; i++) num2.num[i] = '0';
}

// cong 2 so ngyen duong lon va luu ket qua vao mang char
void add(char res[], char *num1, char *num2){
    int c = 0;// phan nho

    for(int i=200; i>=0; i--){
        int tmp = (int)num1[i] - 48 + (int)num2[i] - 48 + c;
        c = tmp / 10;
        res[i] = tmp % 10 + 48;
    }
}

// tru 2 so nguyen duong lon, num1 > num2
void sub(char res[], char *num1, char* num2){
    int c = 0;

    for(int i=200; i>=0; i--){
        int tmp1 = (int)num1[i] - 48;
        int tmp2 = (int)num2[i] - 48;

        if(tmp1 >= tmp2 + c){
            res[i] = tmp1 - tmp2 - c + 48;
            c = 0;
        } else {
            tmp1 = tmp1 + 10;
            res[i] = tmp1 - tmp2 - c + 48;
            c = 1;
        }
    }
}

// nhan 2 so lon
void multi(char res[], char *num1, char *num2){
    // clear array res
    for(int i=0; i<201; i++) res[i] = '0';

    for(int i=200; i>=0; i--){
        // khoi tao mang temp chua ket qua tam thoi
        char tmp[201];

        // dien 0 vao mang temp tuong ung voi hang don vi dang xet
        int k;
        for(k = 0; k < i; k++)
            tmp[200-k] = '0';
        // sau buoc nay ta co k
        int c = 0, sum = 0;
        for(int j=200; j>=0; j--){// so hang thu i cua num1 nhan voi num2
            sum = ((int)num1[i] - 48) * ((int)num2[j] - 48) + c;// so thu i cua num1 nha voi so thu j cua num2 duoc bao nhieu luu kq vao sum
            tmp[k] = (sum % 10) + 48;// luu hang don vi cua sum vao mang kq
            c = sum / 10;// tinh phan du
            k--; if(k < 0) break;// tien den vi tri de luu tiep theo
        }

        add(res,tmp,res);// tong ket qua vua nhan duoc voi ket qua cac lan truoc
    }
}

// check number1 >= number2
bool check(char *num1, char *num2)// chi kiem tra gia tri tuyet doi cua 2 so
{
    int foo1, foo2;
    for(foo1 = 0; foo1 < 201; foo1++){
        if(num1[foo1] != '0') break;
    }// dem so phan tu = '0' trong mang num1 (200-so luong phan tu trong so)

    for(foo2 = 0; foo2 < 201; foo2++){
        if(num2[foo2] != '0') break;
    }//dem so phan tu = '0' trong mang num2 (200-so luong phan tu trong so)

    if(foo1 > foo2) return false;// neu foo1>foo2 (num1 nhieu so hon num2)
    else if(foo1 < foo2) return true;// neu foo1<foo2 (num1 it so hon num2)
    else { // foo1 == foo2
        int foo = foo1;
        while(foo < 201){
            if(num1[foo] < num2[foo]) return false;
            else if (num1[foo] > num2[foo]) return true;
            else {
                foo++;
            }
        }
    }

    return true;
}

// overloading operator "+"
bigNum operator + (bigNum num1, bigNum num2){
    bigNum res;

    if(num1.sign == '1' && num2.sign == '1'){// cong 2 so nguyen duong
        res.sign = '1';
        add(res.num,num1.num,num2.num);
        return res;
    } else if(num1.sign == '1' && num2.sign == '0'){// 1 so duong 1 so am
        if(check(num1.num,num2.num)){// neu so lon ho la so duong, so be hon la so am
            res.sign = '1';
            sub(res.num,num1.num,num2.num);// goi ham tru num1 - num2
            return res;
        } else {// neu so lon ho la so am, so be hon la so duong
            res.sign = '0';
            sub(res.num,num2.num,num1.num);// goi ham tru num2 - num1
            return res;
        }
    } else if(num1.sign == '0' && num2.sign == '1'){// tuong tu TH tren
        if(check(num1.num,num2.num)){
            res.sign = '0';
            sub(res.num,num1.num,num2.num);
            return res;
        } else {
            res.sign = '1';
            sub(res.num,num2.num,num1.num);
            return res;
        }
    } else {// 2 so deu am
        res.sign = '0';
        add(res.num,num1.num,num2.num);
        return res;
    }
}

bigNum operator - (bigNum num1, bigNum num2){
    bigNum res;

    if(num1.sign == '1' && num2.sign == '0'){ // duong - am
        num2.sign = '1';
        res = num1 + num2;
        return res;
    } else if(num1.sign == '1' && num2.sign == '1'){ // duong - duong
        num2.sign = '0';// gan dau num 2 ve am <=> duong + am
        res = num1 + num2;
        return res;
    } else if(num1.sign == '0' && num2.sign == '1'){// tuong tu
        num2.sign = '0';
        res = num1 + num2;
        return res;
    } else { // am - am <=> am + duong
        num2.sign = '1';
        res = num1 + num2;
        return res;
    }
}

bigNum operator * (bigNum num1, bigNum num2){
    bigNum res;

    if(num1.sign == '1' && num2.sign == '1'){// duong * duong
        res.sign = '1';
        multi(res.num,num1.num,num2.num);
        return res;
    } else if(num1.sign == '1' && num2.sign == '0'){//duong * am
        res.sign = '0';
        multi(res.num,num1.num,num2.num);
        return res;
    } else if(num1.sign == '0' && num2.sign == '1'){// am * duong
        res.sign = '0';
        multi(res.num,num1.num,num2.num);
        return res;
    } else { // am * am
        res.sign = '1';
        multi(res.num,num1.num,num2.num);
        return res;
    }
}

// print bignumber
void printBigNumber(bigNum number){
    cout << number.sign;
    int start;
    for(start=0; start<201; start++)
        if(number.num[start] != '0') break;// tim den vi tri bat dau cua so 

    for(int i = start; i<201; i++)
        cout << number.num[i];// in ra so
}

int main(){
    bigNum num1, num2;
    input(num1,num2);

    bigNum so3, so4;
    so3.sign = '1', so4.sign = '1';
    for(int i=0; i<200; i++){
        so3.num[i] = '0';
        so4.num[i] = '0';
    }
    so3.num[200] = 3 + 48;
    so4.num[200] = 4 + 48;

    bigNum res = num1*num2 - so3 * num1 + so4 * num2;

    printBigNumber(res);
}