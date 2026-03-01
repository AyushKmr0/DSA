#include <iostream>
#include <vector>

using namespace std;

int merge(vector<int> &arr, int start, int mid, int end)
{
    vector<int> temp;
    int i = start, j = mid + 1;
    int invCount = 0;

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
            invCount += (mid - i + 1);
        }
    }

    while (i <= mid)
    {
        temp.push_back(arr[i]);
        i++;
    }

    while (j <= end)
    {
        temp.push_back(arr[j]);
        j++;
    }

    for (int idx = 0; idx < temp.size(); idx++)
    {
        arr[start + idx] = temp[idx];
    }

    return invCount;
}

int mergeSort(vector<int> &arr, int start, int end)
{
    if (start < end)
    {
        int mid = start + (end - start) / 2;

        int leftInvCount = mergeSort(arr, start, mid);
        int rightInvCount = mergeSort(arr, mid + 1, end);

        int invCount = merge(arr, start, mid, end);

        return leftInvCount + rightInvCount + invCount;
    }
    return 0;
}

int main()
{
    // vector<int> arr = {6, 3, 5, 2, 7};
    vector<int> arr = {1, 3, 5, 10, 2, 6, 8, 9};

    int ans = mergeSort(arr, 0, arr.size() - 1);
    cout << "Inversion count: " << ans;

    return 0;
}