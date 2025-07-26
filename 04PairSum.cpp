#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

// for sorted array
// // ********using Brute force approch********   -> O(n^2)
vector<int> pairSum1(const vector<int> nums, int target) {
    vector<int> ans;
    int size = nums.size();

    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if(nums[i] + nums[j] == target) {
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
        }
    }

    cout << "end";
    return ans;
}

// for sorted array
// // ********using Two pair approch********    -> O(n)
vector<int> pairSum2(const vector<int> nums, int target) {
    int start = 0, end = nums.size() - 1;
    vector<int> ans;

    while(start < end) {
        int pairsum = nums[start] + nums[end];

        if(pairsum > target) {
            end--;
        } else if (pairsum < target) {
            start++;
        } else  {
            ans.push_back(start);
            ans.push_back(end);
            return ans;
        }
    }

    cout << "end";
    return ans;
}

// for unsorted array
vector<int> pairSum3(vector<int> nums, int target) {
    vector<int> result;
    int size = nums.size();
    vector<pair<int, int>> arr;

    for (int i = 0; i < size; i++) {
        arr.push_back({nums[i], i});
    }

    sort(arr.begin(), arr.end());

    int start = 0, end = size - 1;

    while(start < end) {
        int pairSum = arr[start].first + arr[end].first;

        if(pairSum > target) {
            end--;
        } else if(pairSum < target) {
            start++;
        } else {
            result.push_back(arr[start].second);
            result.push_back(arr[end].second);
            return result;
        }
    }

    cout << "end";
    return result;
}


int main() {
    vector<int> vec = {3,2,4};
    int target = 6;

    // vector<int> result = pairSum1(vec, target);
    // vector<int> result = pairSum2(vec, target);
    vector<int> result = pairSum3(vec, target);

    cout << result[0] << ", " << result[1];

    return 0;
}
