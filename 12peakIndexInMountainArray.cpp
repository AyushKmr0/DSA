/*
852. Peak Index in a Mountain Array

You are given an integer mountain array arr of length n where the values increase to a peak element and then decrease.

Return the index of the peak element.

Your task is to solve it in O(log(n)) time complexity.
*/

#include<iostream>
#include<vector>

using namespace std;

// Using Linear Search Approach
int peakElement1(vector<int>& nums) {
    int size = nums.size();
    if(size == 0)
        return -1;
    if(size == 1)
        return 0;
    
    // Check the first element
    if(nums[0] > nums[1])
        return 0;
    
    for (int i = 1; i < size - 1; i++) {
        if(nums[i-1] < nums[i] && nums[i] > nums[i+ 1]) {
            cout << "PeakElement"<<endl;
            return i;
        }
    }

    // Check the last element
    if(nums[size - 1] > nums[size - 2])
        return size - 1;

    return -1;
}

// Using Binary Search Approach
int peakElement2(vector<int>& nums) {
    int size = nums.size();
    int start = 1, end = size - 2;

    while(start <= end) {
        int mid = start + (end - start) / 2;

        if(nums[mid - 1] < nums[mid] && nums[mid] > nums[mid + 1]) {
            return mid;
        }

            if(nums[mid] > nums[mid - 1]) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
    }
    return -1;
}

int main() {
    vector<int> arr = {0, 3, 4, 5, 8, 9, 8, 7, 5, 2};

    // cout << peakElement1(arr);
    cout << peakElement2(arr); 

    return 0;
}
