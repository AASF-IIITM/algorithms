// C++ program to implement Quick sort with middle element as pivot
#include<bits/stdc++.h>
using namespace std;
  // partition function
int part(int a[], int l, int r) {
  int x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  return j;
}

/* sort arr[left]...arr[right] into increasing order */
void quicksort(int a[], int l, int r) {
  if (l >= r) {
    return;
  }
  // pivot selection
  int k = (l+r)/2;
  swap(a[l], a[k]);
  int m = part(a, l, r);
//   recursion
  quicksort(a, l, m - 1);
  quicksort(a, m + 1, r);
}

// Driver code
int main() {
  int n;  //Number of elements to be sorted
  cin >> n;
  int a[n];
  for (int i = 0; i < n; ++i) {
   cin >> a[i];
  }
  quicksort(a, 0, n - 1);
  for (int i = 0; i < n; ++i) {
   cout << a[i] << ' ';
  }
}