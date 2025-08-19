#include<iostream>
using namespace std;

void bubbleSort(int arr[], int N) { // O(n^2)
    for (int i = 0; i < N - 1; i++) {
        bool isSwap = false;
        for (int j = 0; j < N - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                isSwap = true;
            }
        }
        if(!isSwap) {
            return;
        }
    }
}

void selectionSort(int arr[], int N) {  // O(n^2)
    for (int i = 0; i < N - 1; i++) {
        int smallestIdx = i;
        for (int j = i + 1; j < N; j++) {
            if(arr[j] < arr[smallestIdx]) {
                smallestIdx = j;
            }
        }
        swap(arr[i], arr[smallestIdx]);
    }
}

void insertionSort(int arr[], int N) {  // O(n^2)
    for (int i = 1; i < N; i++) {
        int curr = arr[i], prev = i - 1;

        while (prev >= 0 && arr[prev] > curr) {
            arr[prev + 1] = arr[prev];
            prev--;
        }
        arr[prev + 1] = curr;
    }
}

void printArray(int arr[], int N) {
    for (int i = 0; i < N; i++) {
        cout << arr[i] <<" ";
    }
}
 
int main() {
    int arr[] = {4, 1, 5, 2, 3};
    int N = sizeof(arr) / sizeof(int);

    // bubbleSort(arr, N);
    // selectionSort(arr, N);
    insertionSort(arr, N);

    printArray(arr, N);

    return 0;
}
