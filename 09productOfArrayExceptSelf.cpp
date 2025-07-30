/*
238. Product of Array Except Self

Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.
*/

#include <iostream>
#include <vector>
using namespace std;

// Brute Force Approach
vector<int> productExceptSelf1(vector<int> nums) {
    int size = nums.size();
    vector<int> answer(size, 1);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if(i != j) {
                answer[i] *= nums[j];
            }
        }
    }
    return answer;
}

vector<int> productExceptSelf2(vector<int> &nums)
{
    int size = nums.size();
    vector<int> ans(size, 1);

    for (int i = 1; i < size; i++)
    {
        ans[i] = ans[i - 1] * nums[i - 1];
    }

    int suffix = 1;
    for (int i = size - 2; i >= 0; i--)
    {
        suffix *= nums[i + 1];
        ans[i] *= suffix;
    }

    return ans;
}

int main()
{
    vector<int> num = {1, 2, 3, 4};

    // vector<int> result = productExceptSelf1(num);
    vector<int> result = productExceptSelf2(num);

    for (int val : result)
    {
        cout << val << ", ";
    }
    return 0;
}
