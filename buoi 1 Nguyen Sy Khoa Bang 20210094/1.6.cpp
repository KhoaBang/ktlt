// Viết hàm đảo ngược một mảng các số nguyên theo hai cách: dùng chỉ số và dùng con trỏ.
//Ví dụ mảng đầu vào là [9, -1, 4, 5, 7] thì kết quả là [7, 5, 4, -1, 9].
    void reversearray(int arr[], int size){

        int l = 0, r = size - 1, tmp;
        /*****************

        # YOUR CODE HERE # Nguyen Sy Khoa Bang 20210094

        *****************/
        for (int i=l;i<(size/2);i++){
            tmp =arr[i];// gan phan tu i cua mang vao bien tmp
            arr[i]=arr[r-i];// gan gia tri cua arr[r-i] vao vi tri i
            arr[r-i]=tmp;// gan gia tri arr[i] cu vao vi tri arr[r-i] -> hoan thanh viec doi gia tri cua 2 vi tri i va r-i trong mang arr
        }
    }

    void ptr_reversearray(int *arr, int size){

        int l = 0, r = size - 1, tmp;
        /*****************

        # YOUR CODE HERE # Nguyen Sy Khoa Bang 20210094

        *****************/
        for (int i=l;i<(size/2);i++){
            tmp = *(arr+i);// gan gia tri duoc con tro (arr+i) tro vao (phan tu i cua mang) vao bien tmp
            *(arr+i)=*(arr+r-i);// gan gia tri tham chieu cua con tro (arr+r-i) vao gia tri tham chieu cua con tro (arr+i)
            *(arr+r-i)=tmp;// gan gia tri temp vao gia tri tham chieu cua con tro (arr+r-i)
            //-> hoan thanh viec doi gia tri cua 2 vi tri i va r-i trong mang arr
        }
    }
