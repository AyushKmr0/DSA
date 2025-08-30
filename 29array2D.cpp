#include <iostream>

using namespace std;

// Linear Search
pair<int, int> linearSearch(int matrix[][3], int row, int col, int key) {
    pair<int , int> p(-1, -1);

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if(matrix[i][j] == key) {
                p.first = i;
                p.second = j;
                return p;
            }
        }
    }
    return p;
}

/*
- In 2D Arrays, elements are accessed by tracking the cell position using two indices: row and column.
- For example, matrix[1][2] refers to the element in the 2nd row and 3rd column.
- The total number of elements in a 2D array is given by: total_elements = rows * columns
*/

int main()
{
    int arr[5] = {1, 2, 3, 4, 5}; // Normal array

    int matrix1[4][3] = {
        {1, 2, 3}, 
        {4, 5, 6}, 
        {7, 8, 9}, 
        {10, 11, 12}
    };


    matrix1[2][1] = 10; // Changing the element at 3rd row, 2nd column to 10
    cout << matrix1[2][1] << endl;

    
    // Loop on 2D Array
    
    int matrix[4][3];
    int row = 4, col = 3;

    // Input
    cout << "Enter elements in matrix: " << endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> matrix[i][j];
        }
    }

    // Output 
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }



    // Linear Search
    int key = 5;

    pair<int, int> result = linearSearch(matrix, row, col, key);
    
    if(result.first != -1 && result.second != -1) {
        cout << "Element found at index: (" << result.first << ", " << result.second << ")" << endl;
    } else {
        cout << "Element not found" << endl;
    }

    return 0;
}
