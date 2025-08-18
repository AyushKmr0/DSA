/*
Aggressive Cows Problem

Assign C cows to N stalls such that min distance between them is largest possible. Return largest minimum distance.
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool isPossible(vector<int>& arr, int n, int c, int minDistance) {
    int cows = 1, lastStallPos = arr[0];

    for (int i = 0; i < n; i++) {
        if((arr[i] - lastStallPos) >=minDistance) {
            cows++;
            lastStallPos = arr[i];
        }

        if(cows == c) {
            return true;
        }
    }

    return false;
}

int minDistanceBetweenCow(vector<int>& arr, int c) {
    sort(arr.begin(), arr.end());

    int n = arr.size();
    int start = 1, end = arr[n - 1] - arr[0], ans = -1;

    while(start <= end) {
        int mid = start + (end - start) / 2;

        if(isPossible(arr, n, c, mid)) {
            ans = mid;
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return ans;
}

int main() {
    vector<int> arr = {1, 2, 8, 4, 9};
    int c = 3;

    cout << minDistanceBetweenCow(arr, c);

    return 0;
}
