#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &arr, int st, int mid, int end)
{
    vector<int> temp;
    int i = st, j = mid + 1;

    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            temp.push_back(arr[j]);
            j++;
        }
    }
    while (i <= mid)
    {
        temp.push_back(arr[i]);
        i++;
    }
    while (j <= mid)
    {
        temp.push_back(arr[j]);
        j++;
    }

    for (int idx = 0; idx < temp.size(); idx++)
    {
        arr[st + idx] = temp[idx];
    }
}

void mergeSort(vector<int> &arr, int start, int end)
{
    if (start < end)
    {
        int mid = start + (end - start) / 2;

        mergeSort(arr, start, mid);   // left half
        mergeSort(arr, mid + 1, end); // right half

        merge(arr, start, mid, end);
    }
}

int main()
{
    vector<int> arr = {12, 21, 35, 8, 32, 17};

    mergeSort(arr, 0, arr.size() - 1);

    for (int val : arr)
    {
        cout << val << " ";
    }

    return 0;
}