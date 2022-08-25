#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <math.h>
#define e 2.7
#define E 0.0001
using namespace std;
int fractal(int number_fractal) {
    int answer_fractal = 0;
    for (int i = 0; i <= number_fractal; i++) {
        answer_fractal += i;
    }
    return answer_fractal;
}
double f(double x) {
    double y,x_2;
        x_2=1+pow (x,2);
        y = x*atan(x)-log(x_2);
        return y;
}
float dx(float a, float b, float k) {
    float dxx;
    dxx = (a * b) / k;
    return dxx;

}
double sum(double x, int n) {
    double sum = 1;
    double x2;
    double znam;

    for (int i = 1; i <= n; i++) {
        x2=pow(x,2*i);
        znam=2*n*(2*n-1);
        sum += pow(-1,i+1)*(x2)/znam;
    }
    return sum;
}
float sum_e(double sum) {
    float sum_E = 0;
    if (sum > E) {
        sum_E = int(sum / E);
        sum_E *= 0.0001;
    }
    return sum_E;
}
double miss(double sum, float sum_E) {
    double miss_sum;
    miss_sum = sum - sum_E;
    return miss_sum;
}
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    for(int i=9999999999999;i>1;i++)
    printf("\n%d",i);
}
