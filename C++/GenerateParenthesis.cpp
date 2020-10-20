#include <bits/stdc++.h>
using namespace std;
 
void rec(vector<string>& v, string str, int open, int close, int n) {
    if(str.length() == 2*n) { 
        v.push_back(str);
        return;
    }
    if(open<n) rec(v,str+"(",open+1,close,n);
    if(close<open) rec(v,str+")",open,close+1,n);
}
 
vector<string> generate(int A) {
    vector<string> v;
    rec(v, "", 0, 0, A);
    return v;
}
 
void print(vector<string> res) {
	for(int i = 0; i < int(res.size()); i++) {
		cout << res[i] << endl;
	}
	return;
}
 
int main() {
	int n;
	cin >> n;
	vector<string> res = generate(n);
	print(res);
	return 0;
}
