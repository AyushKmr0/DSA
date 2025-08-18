/*
Painter's Partition Problem

Given are N boards of length of each given in the form of array, and Mpainters, such that each painter takes 1unit of time to paint 1 unit of the board. The task is to find the minimum time to point all boards under the constraints that any painters wil only paint continuous section of boards.
*/

#include<iostream>
#include<vector>
#include<climits>

using namespace std;

bool isPossible(vector<int>& arr, int n, int m, int maxAllowedTime) { // O(n)
    int painters = 1, time = 0;

    for (int i = 0; i < n; i++) {
        if(arr[i] > maxAllowedTime)
            return false;

        if(time + arr[i] <= maxAllowedTime) {
            time += arr[i];
        } else {
            painters++;
            time = arr[i];
        }
    }

    return painters <= m;
}

int minTimeToPaint(vector<int>& arr, int m) {   // O(log(sum) * n)
    int n = arr.size();

    if(m > n) {
        return -1;
    }

    int sum = 0, maxVal = INT_MIN;
    for(int val : arr) {    // O(n)
        maxVal = max(maxVal, val);
        sum += val;
    }

    int start = maxVal, end = sum, ans = -1;

    while(start <= end) {   
        int mid = start + (end - start) / 2;

        if(isPossible(arr, n, m, mid)) {
            ans = mid;
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return ans;
}

int main() {
    vector<int> arr = {40, 30, 10, 20};
    int m = 2;

    cout << minTimeToPaint(arr, m) << endl;
    return 0;
}
