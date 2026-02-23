/*
131. Palindrome Partitioning

Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.


Example 1:
    Input: s = "aab"
    Output: [["a","a","b"],["aa","b"]]

Example 2:
    Input: s = "a"
    Output: [["a"]]


Constraints:
    1 <= s.length <= 16
    s contains only lowercase English letters.
*/

#include <iostream>
#include <vector>

using namespace std;

bool isPalindrome(string s, int start, int end)
{
    while (start <= end)
    {
        if (s[start] != s[end])
            return false;
        start++, end--;
    }
    return true;
}

void getAllParts(string s, int idx, vector<string> &partitions, vector<vector<string>> &result)
{
    if (idx == s.size())
    {
        result.push_back(partitions);
        return;
    }

    for (int i = idx; i < s.size(); i++)
    {
        if (isPalindrome(s, idx, i))
        {
            partitions.push_back(s.substr(idx, i - idx + 1));
            getAllParts(s, i + 1, partitions, result);
            partitions.pop_back();
        }
    }
}

vector<vector<string>> partition(string s)
{
    vector<vector<string>> result;
    vector<string> partitions;

    getAllParts(s, 0, partitions, result);

    return result;
}

int main()
{
    string s = "aab";

    for (const auto &row : partition(s))
    {
        cout << "[ ";
        for (const auto &val : row)
        {
            cout << val << " ";
        }
        cout << "]";
    }

    return 0;
}