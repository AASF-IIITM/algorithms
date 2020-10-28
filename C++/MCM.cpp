/* Given a sequence of matrices, find the most efficient way to multiply these matrices together.

// Naive approach

#include <bits/stdc++.h>
using namespace std;

int MatrixChainOrder(int p[], int i, int j)
{
	if (i == j)
		return 0;
	int k;
	int min = INT_MAX;
	int count;

	for (k = i; k < j; k++) 
	{
		count = MatrixChainOrder(p, i, k) + MatrixChainOrder(p, k + 1, j) + p[i - 1] * p[k] * p[j];

		if (count < min)
			min = count;
	}
  
	return min;
}

*/

// Optimized
#include <bits/stdc++.h>
using namespace std;
int dp[100][100];

int matrixChainMemoised(int* p, int i, int j) {
	if (i == j) 
	{
		return 0;
	}
	if (dp[i][j] != -1) 
	{
		return dp[i][j];
	}
  
	dp[i][j] = INT_MAX;
	for (int k = i; k < j; k++) 
	{
		dp[i][j] = min(dp[i][j], matrixChainMemoised(p, i, k) + matrixChainMemoised(p, k + 1, j) + p[i - 1] * p[k] * p[j]);
	}
	return dp[i][j];
}
int MatrixChainOrder(int* p, int n) {
	int i = 1, j = n - 1;
	return matrixChainMemoised(p, i, j);
}

int main() {
	int arr[] = { 1, 2, 3, 4 };
	int n = sizeof(arr) / sizeof(arr[0]);
	memset(dp, -1, sizeof dp);

	cout << "Minimum number of multiplications is "
		<< MatrixChainOrder(arr, n);
}

