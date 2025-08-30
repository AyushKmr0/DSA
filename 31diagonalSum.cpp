#include<iostream>
#include<vector>
using namespace std;

int diagonalSum1(int matrix[][4], int n) {  // O(n * n)
    int sum = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(i == j) {
                sum += matrix[i][j];
            } else if (j == ((n - 1) - i)) {
                sum += matrix[i][j];
            }
        }
    }
    return sum;
}

int diagonalSum2(int matrix[][4], int n) {  // O(n)
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += matrix[i][i]; // Primary Diagonal

        if (i != ((n - 1) - i)) {
            sum += matrix[i][(n - 1) - i]; // Secondary Diagonal
        }
    }

    return sum;
}


int main() {
    int matrix1[4][4] = { {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16} };

    int n = 4;

    // cout << diagonalSum1(matrix1, n) << endl;
    // cout << diagonalSum2(matrix1, n) << endl;

    
    
    // 2D vector
    vector<vector<int>> matrix2 = {{1, 2, 3}, {4, 5, 6, 10, 11}, {7, 8, 9}};

    /*
    - To calculate the size dynamically, we can use the .size() method
    
    - rows => matrix.size()
    - cols => total number of elements in one row => matrix[0].size()

    - Each row can have a different number of columns, so we can use matrix[i].size() to get the number of columns in each row. e.g. matrix[1].size() will give us the number of columns in the second row.

    e.g. {{1, 2, 3}, 
          {4, 5, 6, 10, 11}, 
          {7, 8, 9}
         }

    */

    for (int i = 0; i < matrix2.size(); i++) {
        for (int j = 0; j < matrix2[i].size(); j++) {
            cout << matrix2[i][j] << " ";
        }
        cout << endl;
    }

        return 0;
}
