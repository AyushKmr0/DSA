/*
11. Container With Most Water

You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.
*/

#include <iostream>
#include <vector>

using namespace std;

// Brute Force Approach to find the maximum area of water that can be stored
int maxArea1(vector<int> &height)
{
    int size = height.size();

    // Stores the maximum area (water) found so far
    int maxWater = 0;

    // Iterate through each pair of lines
    // left line
    for (int i = 0; i < size; i++)
    {
        // right line -> i + 1
        for (int j = i + 1; j < size; j++)
        {
            // Width is the horizontal distance between two lines
            int width = j - i;

            // The height of water is determined by the shorter of the two lines
            int minHeight = min(height[i], height[j]);

            // Area of the container formed by height[i] and height[j]
            int currWater = width * minHeight;

            // Compare and Update maxWater if a bigger area is found
            maxWater = max(maxWater, currWater);
        }
    }

    return maxWater;
}

int maxArea2(vector<int> &height)
{
    // Two pointers approach -> one at the beginning and one at the end
    int left = 0, right = height.size() - 1;

    // Store the maximum water
    int maxWater = 0;

    while (left < right)
    {
        int width = right - left; // Calculate the width between the two lines
        int minHight = min(height[left], height[right]); // minimum Height of the container

        int currWater = width * minHight;

        // Update the maximum water found so far
        maxWater = max(maxWater, currWater);

        // Move the pointer pointing to the shorter line inward
        // (because moving the taller one won't help increase area)
        height[left] < height[right] ? left++ : right--;
    }

    return maxWater;
}


int main()
{
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    // cout << maxArea1(height);
    cout << maxArea2(height);
}
