#include<iostream>
#include <climits>

using namespace std;

int maxRowSum(int matrix[][3], int row, int col) {
    int maxSum = INT_MIN;

    for (int i = 0; i < row; i++)
    {
        int rowSumI = 0;
        for (int j = 0; j < col; j++) {
            rowSumI += matrix[i][j];
        }
        maxSum = max(maxSum, rowSumI);
    }
    return maxSum;
}

int maxColSum(int matrix[][3], int row, int col) {
    int maxSum = INT_MIN;

    for (int i = 0; i < col; i++) {
        int colSumI = 0;
        for (int j = 0; j < row; j++) {
            colSumI += matrix[j][i];
        }
        maxSum = max(maxSum, colSumI);
    }

    return maxSum;
}

int main() {
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 3, 2},
        {7, 1, 0},
    };
    int row = 3, col = 3;

    cout << "Maximum row sum: " << maxRowSum(matrix, row, col) << endl;
    cout << "Maximum column sum: " << maxColSum(matrix, row, col) << endl;

    return 0;
}
