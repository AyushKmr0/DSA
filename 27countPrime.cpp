/*
204. Count Primes

Given an integer n, return the number of prime numbers that are strictly less than n.
*/

#include<iostream>
#include<vector>

using namespace std;

int countPrime1(int nums) {
    int countPrime = 0;
    for (int i = 2; i <= nums; i++){
        bool isPrime = true;

        for (int j = 2; j * j <= i; j++)
        {
            if (i % j == 0)
            {
                isPrime = false;
            }
        }

        if(isPrime == true) {
            countPrime++;
        }
    }

    return countPrime;
}

int countPrime2(int nums) {
    vector<bool> isPrime(nums + 1, true);
    int count = 0;

    for (int i = 2; i < nums; i++) {
        if(isPrime[i]) {
            count++;

            for (int j = i * 2; j < nums; j = j + i) {
                isPrime[j] = false;
            }
        }
    }
    return count;
}

int main() {
    int num = 10;

    // cout << countPrime1(num);
    cout << countPrime2(num);

    return 0;
}
