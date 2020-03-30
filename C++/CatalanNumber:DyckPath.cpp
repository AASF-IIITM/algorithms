/*
Number of Dyck Path or Catalan Numbers
Catalan Number(n)=(2nCn)/(n+1)
Dyck Path: Consider a n x n grid with indexes of top left corner as (0, 0). Dyck path is a staircase walk from bottom left, i.e., (n-1, 0) to top right, i.e., (0, n-1) that lies above the diagonal cells (or cells on line from bottom left to top right).
*/
#include <bits/stdc++.h>
using namespace std;
int catalanNumbers(int n) {
	int num = 1;
	//Calculate 2nCn
	for (int i = 0; i < n; i++) {
		num *= (2 * n - i);
		num /= i + 1;
	}
	//Return 2nCn/(n+1)
	return num / (n + 1);
}
int main() {
	int n = 5;
	cout << catalanNumbers(n) << "\n";
	return 0;
} 
