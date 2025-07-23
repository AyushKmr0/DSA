#include <iostream>
#include <vector>
using namespace std;

// Function to perform Linear Search in a vector
// Parameters: vector (by const reference), target value
void linearSearch(const vector<int>& vec, int target)
{
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] == target) 
        {
            cout << "Target found at index: " << i << endl;
            return;
        }
    }
    cout << "Target not found" << endl;
}

// Function to reverse a vector in-place
// Parameters: vector (by reference so changes apply to original vector)
void reverseVec(vector<int>& vec)
{
    // Using two pointer approach to solve this problem
    int start = 0, end = vec.size() - 1;

    // Swap elements from both ends until they meet in the middle
    while (start < end)
    {
        swap(vec[start], vec[end]);
        start++;
        end--;
    }
}

int main()
{
    vector<int> vec = {3, 5, 3, 5, 7, 2, 8, 6, 4, 1, 9, 0};
    int target = 1;

    // Perform Linear Search
    cout << "\nLinear Search\n";
    linearSearch(vec, target);

    // Print vector before reversing
    cout << "\nReverse vector\n";
    cout << "Before: ";
    for (int val : vec)
        cout << val << " ";
    cout << endl;

    // Reverse the vector
    reverseVec(vec);

    // Print vector after reversing
    cout << "After: ";
    for (int val : vec)
        cout << val << " ";
    cout << endl;

    return 0;
}
