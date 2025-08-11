#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// // ********using Brute force approch********  -> O(n^2)
int majorityElement1(vector<int> nums)
{
    int size = nums.size();
    for (int value : nums)
    {
        int occur = 0;

        for (int element : nums)
        {
            if (value == element)
            {
                occur++;
            }
        }

        if (occur > size / 2)
        {
            return value;
        }
    }
    return -1;
}

// optimized -> O(nlog n)
int majorityElement2(vector<int> nums)
{
    int size = nums.size();

    sort(nums.begin(), nums.end());

    int occur = 1, result = nums[0];
    for (int i = 1; i < size; i++)
    {
        cout << nums[i] << ":" << i << endl;
        if (nums[i] == nums[i - 1])
        {
            occur++;
        }
        else
        {
            occur = 1;
            result = nums[i];
        }

        if (occur > size / 2)
        {
            return result;
        }
    }

    return result;
}

// // ********using Moore's voting algorithm********  -> O(n)
int majorityElement3(vector<int> nums)
{
    int size = nums.size();
    int occur = 0, result = nums[0];
    for (int i = 0; i < size; i++)
    {
        if (occur == 0)
        {
            result = nums[i];
        }

        if (result == nums[i])
        {
            occur++;
        }
        else
        {
            occur--;
        }
    }

    int count = 0;
    for (int val : nums)
    {
        if (val == result)
        {
            count++;
        }
    }

    return (count > size / 2) ? result : -1;
}

int majorityElement4(vector<int> nums) {
    int size = nums.size();
    int occur = 0, result = nums[0];

    for(int val : nums) {
        if(occur == 0) {
            result = val;
        }

        occur += (result == val) ? 1 : -1;
    }

    return result;
}

int main()
{
    vector<int> arr = {2, 1, 2, 1, 2, 1, 1};

    // cout << majorityElement1(arr);
    cout << majorityElement2(arr);
    // cout << majorityElement3(arr);
    // cout << majorityElement4(arr);

    return 0;
}
