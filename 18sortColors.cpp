/*
75. Sort Colors

Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.
*/

#include<iostream>
#include<vector>

using namespace std;

void sortColors1(vector<int>& arr) {
    int N = arr.size();
    int count0 = 0, count1 = 0, count2 = 0;

    for (int i = 0; i < N; i++) {
        if(arr[i] == 0)
            count0++;
        else if(arr[i] == 1)
            count1++;
        else
            count2++;
    }

    int idx = 0;
    for (int i = 0; i < count0; i++) {
        arr[idx++] = 0;
    }
    for (int i = 0; i < count1; i++) {
        arr[idx++] = 1;
    }
    for (int i = 0; i < count2; i++) {
        arr[idx++] = 2;
    }
}

// Using Dutch National Flag Algorithm
void sortColors2(vector<int>& arr) {
    int low = 0, mid = 0, high = arr.size() - 1;

    while (mid <= high)
    {
        if(arr[mid] == 0) {
            swap(arr[low], arr[mid]);
            low++, mid++;
        } else if(arr[mid] == 1) {
            mid++;
        } else {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

void printArray(vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    vector<int> arr = {2, 0, 2, 1, 1, 0};

    cout << "Array : ";
    printArray(arr);

    // sortColors1(arr);
    sortColors2(arr);

    cout << "\nSorted Array : ";
    printArray(arr);

    return 0;
}
