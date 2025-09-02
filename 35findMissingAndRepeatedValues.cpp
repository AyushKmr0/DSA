/*
2965. Find Missing and Repeated Values

You are given a 0-indexed 2D integer matrix grid of size n * n with values in the range [1, n2]. Each integer appears exactly once except a which appears twice and b which is missing. The task is to find the repeating and missing numbers a and b.

Return a 0-indexed integer array ans of size 2 where ans[0] equals to a and ans[1] equals to b.

 

Example 1:
Input: grid = [[1,3],[2,2]]
Output: [2,4]
Explanation: Number 2 is repeated and number 4 is missing so the answer is [2,4].

Example 2:
Input: grid = [[9,1,7],[8,9,2],[3,4,6]]
Output: [9,5]
Explanation: Number 9 is repeated and number 5 is missing so the answer is [9,5].
*/

#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid) {
    vector<int> ans;
    unordered_set<int> set;
    int N = grid.size();
    int a, b;
    int expectedSum = 0, actualSum = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            actualSum += grid[i][j];
            if(set.find(grid[i][j]) != set.end()) {
                a = grid[i][j];
                ans.push_back(grid[i][j]);
            }
            set.insert(grid[i][j]);
        }
    }
    expectedSum = ((N * N) * ((N * N) + 1)) / 2;
    b = (expectedSum + a) - actualSum;
    ans.push_back(b);

    return ans;
}

int main() {
    vector<vector<int>> grid = {{9, 1, 7}, {8, 9, 2}, {3, 4, 6}};

    for(int val : findMissingAndRepeatedValues(grid)) {
        cout << val << " ";
    }

    return 0;
}
