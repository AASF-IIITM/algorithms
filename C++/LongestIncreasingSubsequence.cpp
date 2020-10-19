#include<bits/stdc++.h>
using namespace std;

int lis(vector<int> &A) {
    int n = A.size(), ans = 0;
    vector<int> seq;
    for(int i = 0; i < n; i++) {
        int ind = lower_bound(seq.begin(), seq.end(), A[i]) - seq.begin();
        if(ind == seq.size()) {
            seq.push_back(A[i]);
        } else {
            seq[ind] = A[i];
        }
    }
    return seq.size();
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    cout << lis(arr);
}
