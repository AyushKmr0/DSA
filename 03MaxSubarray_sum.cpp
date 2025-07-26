#include <iostream>
#include <climits>
using namespace std;

int main()
{
    // int n = 5;
    // int arr[5] = {1, 2, 3, 4, 5};

    // for (int start = 0; start < n; start++) {
    //     for (int end = start; end < n; end++) {
    //         for (int i = start; i <= end; i++) {
    //             cout << arr[i];
    //         }
    //         cout << " ";
    //     }
    //     cout << endl;
    // }

    // ******Maximum sumarray sum*******

    int arr[] = {3, -4, 5, 4, -1, 7, -8};
    int size = sizeof(arr) / sizeof(int);
    int maxSum = INT_MIN;

    // ********using Brute force approch********
    // for (int start = 0; start < size; start++) {
    //     int currentSum = 0;
    //     for (int end = start; end < size; end++) {
    //         currentSum += arr[end];
    //         maxSum = max(currentSum, maxSum);
    //     }
    // }
    // cout << maxSum;



    // // ********using Kadane's algorithm********
    int currentSum = 0;
    for(int value : arr) {
        currentSum += value;
        maxSum = max(currentSum, maxSum);

        if(currentSum < 0) {
            currentSum = 0;
        }
    }
    cout << maxSum;

    return 0;
}
