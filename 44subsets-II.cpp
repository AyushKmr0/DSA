/*
90. Subsets II

Given an integer array nums that may contain duplicates, return all possible
subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any
order.


Example 1:
    Input: nums = [1,2,2]
    Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]

Example 2:
    Input: nums = [0]
    Output: [[],[0]]

Constraints:
    -  1 <= nums.length <= 10
    -  -10 <= nums[i] <= 10
*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void getAllSubsets(vector<int>& nums, vector<int>& ans, int i,
                   vector<vector<int>>& allSubsets) {
  if (i == nums.size()) {
    allSubsets.push_back({ans});
    return;
  }

  // Include
  ans.push_back(nums[i]);
  getAllSubsets(nums, ans, i + 1, allSubsets);

  // Backtrack
  ans.pop_back();

  // Prevent form duplicate subsets
  int idx = i + 1;
  while (idx < nums.size() && nums[idx] == nums[idx - 1]) idx++;

  getAllSubsets(nums, ans, idx, allSubsets);
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
  vector<vector<int>> allSubsets;
  vector<int> ans;

  sort(nums.begin(), nums.end());

  getAllSubsets(nums, ans, 0, allSubsets);

  return allSubsets;
}

void displaySubset(vector<vector<int>> nums) {
  cout << "[";
  for (int i = 0; i < nums.size(); i++) {
    cout << " [ ";
    for (int j = 0; j < nums[i].size(); j++) {
      cout << nums[i][j] << " ";
    }
    cout << "] ";
  }
  cout << "]";
}

int main() {
  vector<int> nums = {4, 4, 4, 1, 4};

  vector<vector<int>> result = subsetsWithDup(nums);
  displaySubset(result);

  return 0;
}
