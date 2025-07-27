#include<iostream>
using namespace std;

double myPow(double x, int n) {
    if(x == 0) return 0.0;
    if(x == 1 || n == 0) return 1.0;
    if(x == -1 && n%2 == 0) return 1.0;
    if(x == -1 && n%2 != 0) return -1.0;

    long long power = n;
    double ans = 1.0;

    if(power < 0) {
        x = 1 / x;
        power = -power;
    }

    while (power > 0)
    {
        if(power % 2 == 1) {
            ans *= x;
        }
        x *= x;
        power /= 2;
    }

    return ans;
}

int main() {
    double x = -1;
    int n = 6;

    cout<<myPow(x, n);

    return 0;
}
