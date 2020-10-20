#include <bits/stdc++.h>
using namespace std;
 
void generate(int index, int n, vector<int>& v, vector<vector<int>>& res, vector<int> A) {
    if(index == n ) {
        res.push_back(v);
        return;
    }
    for(int i = 0; i < n; i++) {
        if(v[i] == -1) {
            v[i] = A[index];
            generate(index + 1, n, v, res, A);
            v[i] = -1;
        }
    }
}
 
vector<vector<int>> permute(vector<int> &A) {
    vector<vector<int>> res;
    int n = A.size();
    vector<int> v(n, -1);
    generate(0, n, v, res, A);
    return res;
}
 
void print(vector<vector<int>> res) {
	for(int i = 0; i < int(res.size()); i++) {
		for(int j = 0; j < int(res[i].size()); j++) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
	return;
}
 
int main() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i = 0; i < n; i++) cin >> arr[i];
	vector<vector<int>> res = permute(arr);
	print(res);
	return 0;
}
