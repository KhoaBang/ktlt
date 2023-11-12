#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

const int LIMIT = 100;
const int NUM_ITER = 100000;
const int NUM_INPUTS = NUM_ITER * 100;

double sigmoid_slow(double x) {
    return 1.0 / (1.0 + exp(-x));
}

double x[NUM_INPUTS];

void prepare_input() {
    const int PRECISION = 1000000;
    const double RANGE = LIMIT / 20.0;
    for (int i = 0; i < NUM_INPUTS; ++i) {
        x[i] = RANGE * (rand() % PRECISION - rand() % PRECISION) / PRECISION;
    }
}

//# BEGIN fast code

//# khai báo các biến phụ trợ cần thiết
/*****************
# YOUR CODE HERE #
*****************/
const int N=100000;
double k[N+1];
//# hàm chuẩn bị dữ liệu
void precalc()// tao bang look up cho ham sigmoid voi cac gia tri x đau vào thuoc khoang
{
    /*****************
    # YOUR CODE HERE #
     Nguen Sy Khoa Bang 20210094
    *****************/
    double delta = (LIMIT*2.0)/N;// tinh buoc nhay delta
    for(int i=0;i<=N;i++) // voi tung i trong khoang ( i cach i+1 mot khoang bang delta)
    {
        k[i]=sigmoid_slow(-LIMIT+delta*i);// tinh sigmoid roi lu vao trong mang
    }
}

//# hàm tính sigmoid(x) nhanh sigmoid_fast(x)
inline double sigmoid_fast(double x) {
    /*****************
    # YOUR CODE HERE #
     Nguyen Sy Khoa Bang 20210094
    *****************/
    if(x<-LIMIT) return 0;// neu gia tri dau vao be hon nguong da tinh san
    if(x>=+LIMIT) return 1;// neu gia tri dau vao lon hon nguong da tinh san
    static double delta = (LIMIT*2.0)/N;// tinh lai delta
    int i = (x+LIMIT)/delta;// anh xa tu x sang i de look up ham
    return (x-(-LIMIT +(delta*i)))/delta*(k[i+1]-k[i])+k[i];//
}

//# END fast code

double benchmark(double (*calc)(double), vector<double> &result) {
    const int NUM_TEST = 20;

    double taken = 0;
    result = vector<double>();
    result.reserve(NUM_ITER);

    int input_id = 0;
    clock_t start = clock();
    for (int t = 0; t < NUM_TEST; ++t) {
        double sum = 0;
        for (int i = 0; i < NUM_ITER; ++i) {
            double v = fabs(calc(x[input_id]));
            sum += v;
            if (t == 0) result.push_back(v);
            if ((++input_id) == NUM_INPUTS) input_id = 0;
        }
    }
    clock_t finish = clock();
    taken = (double)(finish - start);
//#  printf("Time: %.9f\n", taken / CLOCKS_PER_SEC);
    return taken;
}

bool is_correct(const vector<double> &a, const vector<double> &b) {
    const double EPS = 1e-6;

    if (a.size() != b.size()) return false;
    for (int i = 0; i < (int)a.size(); ++i) {
        if (fabs(a[i] - b[i]) > EPS) {
            return false;
        }
    }
    return true;
}

int main() {
    prepare_input();
    precalc();

    vector<double> a, b;
    double slow = benchmark(sigmoid_slow, a);
    double fast = benchmark(sigmoid_fast, b);

    double xval;
    scanf("%lf", &xval);
    printf("%.2f \n", sigmoid_fast(xval));

    if (is_correct(a, b) && (slow/fast > 1.3)) {
        cout<<("Correct answer! Your code is faster at least 30%! \n");
    } else {
        cout<<("Wrong answer or your code is not fast enough!\n");
    }

    return 0;
}