/*
54. Spiral Matrix

Given an m x n matrix, return all elements of the matrix in spiral order.

 
Example 1:

Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
*/

#include<iostream>
#include<vector>

using namespace std;

vector<int> searchMatrix(vector<vector<int>> &matrix) {
    vector<int> ans;
    int m = matrix.size(), n = matrix[0].size();
    int srow = 0,  erow = m - 1, scol = 0, ecol = n - 1;

    while(srow <= erow && scol <= ecol)  {
        for (int j = scol; j <= ecol; j++) {
            ans.push_back(matrix[srow][j]);
        }

        for (int i = srow + 1; i <= erow; i++) {
            ans.push_back(matrix[i][ecol]);
        }

        for (int j = ecol - 1; j >= scol; j--) {
            if(scol == ecol) break;
            ans.push_back(matrix[erow][j]);
        }

        for (int i = erow - 1; i >= srow + 1; i--) {
            if(srow == erow) break;
            ans.push_back(matrix[i][scol]);
        }

        srow++, erow--, scol++, ecol--;
    }
    return ans;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3, 4}, 
        {5, 6, 7, 8}, 
        {9, 10 , 11, 12},
        {13, 14, 15, 16}
    };

    vector<int> result = searchMatrix(matrix);
    for(int val : result) {
        cout << val << " ";
    }

    return 0;
}
