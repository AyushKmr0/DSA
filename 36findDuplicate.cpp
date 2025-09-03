/*
287. Find the Duplicate Number

Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and using only constant extra space.

 

Example 1:
Input: nums = [1,3,4,2,2]
Output: 2

Example 2:
Input: nums = [3,1,3,4,2]
Output: 3
*/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int findDuplicate1(vector<int> &arr) {
    int N = arr.size();
    int duplicateItem = -1;
    unordered_set<int> set;

    for(int val : arr) {
        if(set.find(val) != set.end()) {
            return duplicateItem = val;
        }
        set.insert(val);
    }

    return duplicateItem;
}

int findDuplicate2(vector<int> &arr) {
    int slow = arr[0], fast = arr[0];

    do{
        slow = arr[slow];
        fast = arr[arr[fast]];

        if(slow == fast) {
            break;
        }
    } while (slow != fast);

    slow = arr[0];
    while(slow != fast) {
        slow = arr[slow];
        fast = arr[fast];
    }

    return slow;
}

int main()
{
    vector<int> arr = {1, 3, 3, 4, 3};
    cout << findDuplicate1(arr) << endl;
    cout << findDuplicate2(arr) << endl;
    return 0;
}

