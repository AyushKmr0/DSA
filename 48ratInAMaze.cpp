#include <iostream>
#include <vector>

using namespace std;

void helper(vector<vector<int>> &mat, int row, int col, string path, vector<string> &ans)
{
    int size = mat.size();
    if (row < 0 || col < 0 || row >= size || col >= size || mat[row][col] == 0 || mat[row][col] == -1)
    {
        return;
    }

    if (row == size - 1 && col == size - 1)
    {
        ans.push_back(path);
        return;
    }

    mat[row][col] = -1; // visit

    helper(mat, row + 1, col, path + "D", ans); // down
    helper(mat, row - 1, col, path + "U", ans); // up
    helper(mat, row, col + 1, path + "R", ans); // right
    helper(mat, row, col - 1, path + "L", ans); // left

    mat[row][col] = 1; // unvisit
}

vector<string> findPath(vector<vector<int>> &mat)
{
    int size = mat.size();
    vector<string> ans;
    string path = "";

    helper(mat, 0, 0, path, ans);
    return ans;
}

int main()
{
    vector<vector<int>> mat = {{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};

    vector<string> ans = findPath(mat);

    for (string path : ans)
    {
        cout << path << endl;
    }

    return 0;
}