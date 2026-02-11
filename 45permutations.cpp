/*
46. Permutations

Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.


Example 1:
    Input: nums = [1,2,3]
    Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

Example 2:
    Input: nums = [0,1]
    Output: [[0,1],[1,0]]

Example 3:
    Input: nums = [1]
    Output: [[1]]

Constraints:
    -  1 <= nums.length <= 6
    -  -10 <= nums[i] <= 10
    -  All the integers of nums are unique.
*/

#include <iostream>
#include <vector>

using namespace std;

void getPerms(vector<int> &nums, int idx, vector<vector<int>> &ans)
{
    if (idx == nums.size())
    {
        ans.push_back({nums});
        return;
    }

    for (int i = idx; i < nums.size(); i++)
    {
        swap(nums[idx], nums[i]);
        getPerms(nums, idx + 1, ans);
        swap(nums[idx], nums[i]);
    }
}

vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> ans;

    getPerms(nums, 0, ans);

    return ans;
}

void displayPermute(vector<vector<int>> nums)
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

    vector<vector<int>> result = permute(nums);
    displayPermute(result);

    return 0;
}