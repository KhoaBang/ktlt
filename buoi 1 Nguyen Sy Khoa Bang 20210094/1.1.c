# include <stdio.h>
int main(){
    int x, y, z;
    int* ptr;
    printf("Enter three integers: ");// in prompt
    scanf("%d %d %d", &x, &y, &z);// nhap lieu
    printf("\nThe three integers are:\n");
    ptr = &x;// con tro ptr chua dia chi cua x
    printf("x = %d\n", *ptr);// in ra noi dung ptr tro den (noi dung cua x)
/*****************
# YOUR CODE HERE # Nguyen Sy Khoa Bang 20210094
*****************/
    ptr =&y;// con tro ptr chua dia chi cua y
    printf("y = %d\n",*ptr);// in ra noi dung ptr tro den (noi dung cua y)
    ptr =&z;// con tro ptr chua dia chi cua z
    printf("z = %d\n",*ptr);// in ra noi dung ptr tro den (noi dung cua z)
    return 0;
}