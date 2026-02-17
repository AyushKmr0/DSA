/*
560. Subarray Sum Equals K

Given an array of integers nums and an integer k, return the total number of
subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.


Example 1:
    Input: nums = [1,1,1], k = 2
    Output: 2

Example 2:
    Input: nums = [1,2,3], k = 3
    Output: 2


Constraints:
   -  1 <= nums.length <= 2 * 104
   -  -1000 <= nums[i] <= 1000
   -  -107 <= k <= 107
*/

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// Brute-force approach  --> TC : O(n²), SC : O(1)
int subarraySum1(vector<int>& nums, int k) {
  int size = nums.size();
  int count = 0;

  for (int i = 0; i < size; i++) {
    int sum = 0;
    for (int j = i; j < size; j++) {
      sum += nums[j];
      if (sum == k) count++;
    }
  }

  return count;
}

// Optimal approach  -->  TC : O(n), SC : O(n)
int subarraySum2(vector<int>& nums, int k) {
  int size = nums.size();
  vector<int> prefixSum(size);
  int count = 0;

  prefixSum[0] = nums[0];
  for (int i = 1; i < size; i++) {
    prefixSum[i] = prefixSum[i - 1] + nums[i];
  }

  unordered_map<int, int> m;

  for (int j = 0; j < size; j++) {
    if (prefixSum[j] == k) count++;

    int diff = prefixSum[j] - k;
    if (m.find(diff) != m.end()) {
      count += m[diff];
    }

    if (m.find(prefixSum[j]) == m.end()) {
      m[prefixSum[j]] = 0;
    }

    m[prefixSum[j]]++;
  }
  return count;
}

int subarraySum3(vector<int>& nums, int k) {
  unordered_map<int, int> m;
  int prefixSum = 0, count = 0;

  for (int val : nums) {
    prefixSum += val;

    if (prefixSum == k) count++;

    if (m.find(prefixSum - k) != m.end()) {
      count += m[prefixSum - k];
    }
    m[prefixSum]++;
  }
  return count;
}

int main() {
  vector<int> nums = {9, 4, 0, 20, 3, 10, 5};
  int k = 33;

  //   cout << subarraySum1(nums, k);
  //   cout << subarraySum2(nums, k);
  cout << subarraySum3(nums, k);

  return 0;
}