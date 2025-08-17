/*
Allocate Minimum Pages

Given an array arr[] of integers, where each element arr[i] represents the number of pages in the i-th book. You also have an integer m representing the number of students. The task is to allocate books to each student such that:

- Each student receives atleast one book.
- Each student is assigned a contiguous sequence of books.
- No book is assigned to more than one student.

The objective is to minimize the maximum number of pages assigned to any student. In other words, out of all possible allocations, find the arrangement where the student who receives the most pages still has the smallest possible maximum.

Note: If it is not possible to allocate books to all students, return -1.
*/

#include<iostream>
#include<vector>

using namespace std;

bool isValid(vector<int>& arr, int n, int m, int maxAllowedPages) {
    int students = 1, pages = 0;

    for (int i = 0; i < n; i++) {
        if(arr[i] > maxAllowedPages)
            return false;

        if(pages + arr[i] <= maxAllowedPages) {
            pages += arr[i];
        } else {
            students++;
            pages = arr[i];
        }
    }

    return students > m ? false : true;
}

int allocateBook(vector<int>& arr, int n, int m) {
    if(m > n) {
        return -1;
    }

    int sum = 0;

    for(int val : arr) {
        sum += val;
    }

    int ans = -1;
    int start = 0, end = sum;   // range of possible ans

    while(start <= end) {
        int mid = start + (end - start) / 2;

        if(isValid(arr, n, m, mid)) {   // left
            ans = mid;
            end = mid - 1;
        } else {    // right
            start = mid + 1;
        }
    }
    return ans;
}

int main() {
    vector<int> arr = {2, 1, 3, 4};
    int n = 4, m = 2;

    cout << allocateBook(arr, n, m);

    return 0;
}
