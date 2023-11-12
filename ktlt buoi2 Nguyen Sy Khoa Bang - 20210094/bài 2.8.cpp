#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    int val1, val2;
    cin >> val1 >> val2;// nhap gia tri
    vector< vector<int> > a = {
            {1, 3, 7},
            {2, 3, 4, val1},
            {9, 8, 15},
            {10, val2},
    };

    //# sắp xếp các vector trong a theo tổng các phần tử giảm dần
    /*****************
    # YOUR CODE HERE #
     Nguyen Sy Khoa Bang 20210094
    *****************/
    sort(a.begin(), a.end(),[](const vector<int> &p,// xu dung ham sort de sap xep cac vector
            const vector<int> &q){return accumulate(p.begin(),p.end(),0)// tinh tong 1 vector
            > accumulate(q.begin(),q.end(),0);}//ham so sanh tong 2 vector, tra lai true neu vt1> vt2
            );

    for (const auto &v : a)// vong lap de in ra noi dung trong tap vector da sap xep
    {
        for (int it : v) {
            cout << it << ' ';
        }
        cout << endl;
    }
    return 0;
}