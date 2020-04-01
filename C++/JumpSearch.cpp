// Jump Search implementation
// Time Complexity: O(√n)
#include<bits/stdc++.h>
int jumpSort(int a[], int n, int key) {
	//To find the jump length
	int m = sqrt(n);
	int i;
	//Finding the block in which the required element lies
	for (i = 0; i < n; i += m) {
		if (a[i] >= key) {
			break;
		}
	}
	//Returning the index of the element
	if (a[i] == key) {
		return i;
	}
	else {
		int temp = i;
		for (i -= m; i < temp; i++) {
			if (a[i] == key) {
				break;
			}
		}
		return i;
	}
}
using namespace std;
int main () {
	int a[20] = {1, 22, 34, 45, 54, 61, 70, 82, 93, 96, 99, 100, 113, 124, 135, 176, 277, 858, 969, 999};
	int n = sizeof(a) / sizeof(a[0]);
	cout << "99 is located at index i = " << jumpSort(a, n, 99) << "\n";
	return 0;
}