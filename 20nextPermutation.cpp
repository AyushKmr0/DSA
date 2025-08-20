/*
31. Next Permutation

A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

For example, the next permutation of arr = [1,2,3] is [1,3,2].

Similarly, the next permutation of arr = [2,3,1] is [3,1,2].

While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.

Given an array of integers nums, find the next permutation of nums.

The replacement must be in place and use only constant extra memory.
*/ 

#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

void nextPermutation(vector<int>& arr) {
    // find the pivot element
    int pivot = -1, n = arr.size();
    for (int i = n - 2; i >= 0; i--) {
        if(arr[i] < arr[i+1]) {
            pivot = i;
            break;
        }
    }

    if(pivot == -1) {
        reverse(arr.begin(), arr.end());
        return;
    }

    // find the greatest element then pivot between pivot + 1 to n - 1;
    for (int i = n - 1; i > pivot; i--) {
        if(arr[i] > arr[pivot]) {
            swap(arr[i], arr[pivot]);
            break;
        }
    }

    // find the smallest possible arrangement
    int i = pivot + 1, j = n - 1;
    while (i <= j)
    {
        swap(arr[i], arr[j]);
        i++, j--;
    }
}

void displayArray(vector<int>& arr) {
    for(int val : arr) {
        cout << val <<" ";
    }
}

int main() {
    vector<int> arr = {1, 2, 5, 4, 3};

    cout << "Array: ";
    displayArray(arr);

    nextPermutation(arr);
    // next_permutation(arr.begin(), arr.end());   // Direct way in one line

    cout << "\nNext Permutation : ";
    displayArray(arr);

    return 0;
}
