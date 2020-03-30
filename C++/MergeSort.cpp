/* Merge Sort implementation
Basic Steps:
Step 1 − If there is only one element in the list it is already sorted, return.
Step 2 − Divide the list recursively into two halves until it can no more be divided.
Step 3 − Merge the smaller lists into new list in sorted order.

Time Complexity: O(nlogn)
*/
#include <bits/stdc++.h>
using namespace std;
//Merging function
void mergeArray(int *a, int s, int e) {

	int mid = (s + e) / 2;
	int i = s, j = mid + 1;
	int k = s;

	int temp[10004];
	while (i <= mid && j <= e) {
		if (a[i] < a[j])
			temp[k++] = a[i++];
		else
			temp[k++] = a[j++];
	}
	while (i <= mid)
		temp[k++] = a[i++];
	while (j <= e)
		temp[k++] = a[j++];
	//Copying the elements into original array
	for (int i = s; i <= e; i++)
		a[i] = temp[i];

}
//Recursion Function
void mergeSort(int a[], int s, int e) {
	//Base Case -1 or 0 elements
	if (s >= e)
		return;

	//1.Divide
	int mid = (s + e) / 2;

	//2.Conquer that is - use the recursion step
	mergeSort(a, s, mid);
	mergeSort(a, mid + 1, e);

	//3.Merge the two parts
	mergeArray(a, s, e);
}

int main() {
	int a[8] = {7, 1, 3, 8, 0, 5, 3, 10};
	int n = sizeof(a) / sizeof(a[0]);
	mergeSort(a, 0, n - 1);
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << "\n";
}

