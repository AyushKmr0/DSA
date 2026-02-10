/*
78. Subsets

Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:
    Input: nums = [1,2,3]
    Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

Example 2:
    Input: nums = [0]
    Output: [[],[0]]

Constraints:
    1 <= nums.length <= 10
    -10 <= nums[i] <= 10
    All the numbers of nums are unique.
*/

#include <iostream>
#include <vector>

using namespace std;
// TC : O(2ⁿ * n)
void getAllSubsets(vector<int> &nums, vector<int> &ans, int i, vector<vector<int>> &allSubsets)
{
  if (i == nums.size())
  {
    allSubsets.push_back({ans});
    return;
  }

  // include
  ans.push_back(nums[i]);
  getAllSubsets(nums, ans, i + 1, allSubsets);

  ans.pop_back(); // backtrack
  // exclude
  getAllSubsets(nums, ans, i + 1, allSubsets);
}

vector<vector<int>> subsets(vector<int> &nums)
{
  vector<vector<int>> allSubsets;
  vector<int> ans;

  getAllSubsets(nums, ans, 0, allSubsets);

  return allSubsets;
}

void displaySubset(vector<vector<int>> nums)
{
  cout << "[";
  for (int i = 0; i < nums.size(); i++)
  {
    cout << " [ ";
    for (int j = 0; j < nums[i].size(); j++)
    {
      cout << nums[i][j] << " ";
    }
    cout << "] ";
  }
  cout << "]";
}

int main()
{
  vector<int> nums = {1, 2, 3};

  vector<vector<int>> result = subsets(nums);
  displaySubset(result);

  return 0;
}