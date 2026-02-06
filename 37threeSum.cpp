/*
15. 3Sum

Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]]
such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.



# Example 1:
    Input: nums = [-1,0,1,2,-1,-4]
    Output: [[-1,-1,2],[-1,0,1]]

    Explanation:
    nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
    nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
    nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.

The distinct triplets are [-1,0,1] and [-1,-1,2].

Notice that the order of the output and the order of the triplets does not
matter.

# Example 2:
    Input: nums = [0,1,1]
    Output: []

    Explanation:
    The only possible triplet does not sum up to 0.

# Example 3:
    Input: nums = [0,0,0]
    Output: [[0,0,0]]

    Explanation:
    The only possible triplet sums up to 0.
*/

#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

// Brute Force approach  -->  TC : O(n³ * log (uniqueTriplet)),  SC :
// O(uniqueTriplet)
vector<vector<int>> threeSum1(vector<int> arr) {
  vector<vector<int>> ans;

  set<vector<int>> s;

  for (int i = 0; i < arr.size(); i++) {
    for (int j = i + 1; j < arr.size(); j++) {
      for (int k = j + 1; k < arr.size(); k++) {
        if ((arr[i] + arr[j] + arr[k]) == 0) {
          vector<int> trip = {arr[i], arr[j], arr[k]};
          sort(trip.begin(), trip.end());

          if (s.find(trip) == s.end()) {
            s.insert(trip);
            ans.push_back(trip);
          }
        }
      }
    }
  }
  return ans;
}

// HashSet-based approach  -->  TC : O(n² * log (uniqueTriplet)),  SC :
// O(uniqueTriplet + n)
vector<vector<int>> threeSum2(vector<int> arr) {
  int n = arr.size();
  set<vector<int>> uniqueTriplet;

  for (int i = 0; i < n; i++) {
    set<int> s;

    for (int j = i + 1; j < n; j++) {
      // a + b + c --> c = -(a + b)
      int toFind = -(arr[i] + arr[j]);

      if (s.find(toFind) != s.end()) {
        vector<int> trip = {arr[i], arr[j], toFind};
        sort(trip.begin(), trip.end());
        uniqueTriplet.insert(trip);
      }
      s.insert(arr[j]);
    }
  }

  vector<vector<int>> result(uniqueTriplet.begin(), uniqueTriplet.end());
  return result;
}

// 2-Pointer Approach  -->  TC : O(nlog n + n²),  SC : O(uniqueTriplet)
vector<vector<int>> threeSum3(vector<int> arr) {
  vector<vector<int>> result;
  int n = arr.size();

  sort(arr.begin(), arr.end());

  for (int i = 0; i < n; i++) {
    if (i > 0 && arr[i] == arr[i - 1]) continue;

    int j = i + 1, k = n - 1;

    while (j < k) {
      int sum = arr[i] + arr[j] + arr[k];

      if (sum > 0) {
        k--;
      } else if (sum < 0) {
        j++;
      } else {
        result.push_back({arr[i], arr[j], arr[k]});
        j++, k--;

        while (j < k && arr[j] == arr[j - 1]) j++;
      }
    }
  }
  return result;
}

int main() {
  vector<int> arr = {-1, 0, 1, 2, -1, -4};

  //   vector<vector<int>> result = threeSum1(arr);
  //   vector<vector<int>> result = threeSum2(arr);

  vector<vector<int>> result = threeSum3(arr);

  for (int i = 0; i < result.size(); i++) {
    for (int j = 0; j < result[i].size(); j++) {
      cout << result[i][j] << ", ";
    }
    cout << endl;
  }

  return 0;
}