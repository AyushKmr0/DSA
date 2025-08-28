#include<iostream>
#include<vector>

using namespace std;

// Print Digits
int printDigit(int n) {
    int revNum = 0;

    while(n != 0) {
        revNum = (revNum * 10) + (n % 10);
        n /= 10;
    }
    return revNum;
}

// Armmstrong
bool isArmstrong(int n) {
    int copyN = n;
    int sumOfCube = 0;

    while(n != 0) {
        int dig = n % 10;
        sumOfCube += (dig * dig * dig);

        n /= 10;
    }

    return sumOfCube == copyN;
}

// GCD 
int gcd(int a, int b) {
    while(a > 0 && b > 0) {
        if(a > b) {
            a = a - b;
        } else {
            b = b - a;
        }
    }

    return a == 0 ? b : a;
}

// GCD using recursion 
int gcdRev(int a, int b) {
    if(b == 0)
        return a;

    return gcdRev(b, a % b);
}

int main() {
    int n = 153 ;
    cout << "Rever Digit : " << printDigit(n) << endl;

    if(isArmstrong(n)) {
        cout << "Armstrong Number" << endl;
    } else {
        cout << "Not an Armstrong Number" << endl;
    }

    int a = 20, b = 28;
    cout << "GCD : " << gcd(6, 12) << endl;
    cout << "GCD using Recursion : " << gcdRev(6, 12) << endl;


    return 0;
}
