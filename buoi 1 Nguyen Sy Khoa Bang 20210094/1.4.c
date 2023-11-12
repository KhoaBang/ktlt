//Viết hàm countEven(int*, int) nhận một mảng số nguyên và kích thước của mảng, trả về số lượng
//số chẵn trong mảng.
/*****************

# YOUR CODE HERE # Nguyen Sy Khoa Bang 20210094

*****************/
int counteven(int* arr, int size){// nhan vao doi so la con tro int va gia tri int
    int count = 0;// khoi tao bien dem =0
    for (int i =0; i<size;i++){// khoi tao vong lap de kiem tra tung phan tu trong mang
        if (arr[i]%2==0) count++;// neu la so chan, tang bien dem them 1
    }
    return count;// tra lai so luong so chan trong mang
}
