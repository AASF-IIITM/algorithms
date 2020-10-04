/*
  A C++ program to find kth smallest element tn the array.(without sorting the array)
  algorithm :
  first partiton the array taking  last element as pivot.
  now recur on one side of the array according to the position of pivot, i.e.
  recur on left side if pos < k
  recur on right side if pos > k
  return pivot if pos = k
*/
#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int l, int r);

int kthSmallest(int arr[], int l, int r, int k)
{
    if (k > 0 && k <= r - l + 1)
    {
        int pos = partition(arr, l, r);
        if (pos - l == k - 1)
            return arr[pos];
        if (pos - l > k - 1)
            return kthSmallest(arr, l, pos - 1, k);

        return kthSmallest(arr, pos + 1, r, k - pos + l - 1);
    }
}
int partition(int arr[], int l, int r)
{
    // partition taking last element as pivot
    int x = arr[r], i = l;
    for (int j = l; j <= r - 1; j++)
    {
        if (arr[j] <= x)
        {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[r]);
    return i;
}

int main()
{
    int n;
    cin >> n; // no of elements in the array
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int k;
    cin >> k; // k should be less than n
    cout << " ans :  " << kthSmallest(arr, 0, n - 1, k);
    return 0;
}
/*
worst case complexity : O(n^2)
average time complexity : O(n)
*/
