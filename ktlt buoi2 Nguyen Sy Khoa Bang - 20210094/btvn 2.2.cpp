#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;
// Nguyen Sy Khoa Bang 20210094
vector<pair<int, int>> input;
void nhap(ifstream& file) { // ham doc du lieu tu file
    int k, v;
    while (file >> k && file >> v) {
        pair<int, int> p = make_pair(k, v);
        input.push_back(p);
    }
}
void input1(){
    string inputFilePath = "D:\\test.txt";// file chua test case
    ifstream newfile(inputFilePath);

    if (!newfile.is_open()) {
        cerr << "Error opening the file." << endl;
    }
    nhap(newfile);
    newfile.close();
}

int main() {
    input1();
    sort(input.begin(),input.end(),[](const pair<int,int> &a,pair<int,int> &b){if (a.second ==b.second)return (a.first > b.first);else return (a.second >b.second);});
    // ham sap xep
    for (auto v : input){
        cout << v.first<<' '<<v.second<<'\n';// in ra ket qua
    }
    return 0;
}
