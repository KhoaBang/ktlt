#include <stdio.h>

void print(int n) {// khoi tao ham print
    printf("n=%d\n", n);
}

int mul3plus1(int n) { // khoi tao ham n*3 +1
    return n * 3 + 1;
}

int div2(int n) { // khoi tao ham n/2
    return n / 2;
}

// khai báo các tham số cho các con trỏ hàm odd, even và output
void simulate(int n, int (*odd)(int n),int (*even)(int n), void (*output)(int n))  {// truyen doi so la n, con tro ham
    (*output)(n);// thuc hien ham dc con tro output tro toi
    if (n == 1) return;// neu n == 1 thoat ham
    if (n % 2 == 0) { // neu chan
        n = (*even)(n);// goi ham duoc tro to boi con tro even
    } else { // neu le
        n = (*odd)(n);// goi ham duoc tro toi boi con tro odd
    }
    simulate(n, odd, even, output);// de quy
}

int main() {
    int (*odd)(int) = NULL;// khoi tao con tro ham odd tro vao null
    int (*even)(int) = NULL;// khoi tao con tro ham even tro vao null
    /*****************
    # YOUR CODE HERE #
     Nguyen Sy Khoa Bang 20210094
    *****************/
     odd=&mul3plus1;// tro con tro odd vao ham mul3plus1
     even=&div2; // tro con tro even vao ham div2
    int n;
    scanf("%d", &n);// nhap n
    simulate(n, odd, even, print);// goi ham simulate

    return 0;
}