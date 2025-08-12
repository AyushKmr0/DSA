#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> &nums, int target)
{
    int start = 0, end = nums.size() - 1;

    while (start <= end)
    {
        // int mid = (start + end) / 2;
        int mid = start + (end - start) / 2;

        if (target > nums[mid])
        {
            start = mid + 1;
        }
        else if (target < nums[mid])
        {
            end = mid - 1;
        }
        else
        {
            return mid;
        }
    }

    return -1;
}

// Binary Search With Recursion
int binarySearchWithRecursion(vector<int> nums, int target, int start, int end)
{ 
    if (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (target > nums[mid])
        {
            return binarySearchWithRecursion(nums, target, mid + 1, end);
        }
        else if (target < nums[mid])
        {
            return binarySearchWithRecursion(nums, target, start, mid - 1);
        }
        else
        {
            return mid;
        }
    }
    return -1;
}

int main()
{
    vector<int> arr1 = {-1, 0, 3, 4, 5, 9, 12}; // odd
    int tar1 = 12;
    // cout << binarySearch(arr1, tar1);

    vector<int> arr2 = {-1, 0, 3, 5, 9, 12}; // even
    int tar2 = 0;
    // cout << binarySearch(arr2, tar2);

    vector<int> arr3 = {-1, 0, 3, 5, 9, 12}; // even
    int tar3 = 12;
    int start = 0, end = arr3.size() - 1;
    cout << binarySearchWithRecursion(arr3, tar3, start, end);

    return 0;
}
