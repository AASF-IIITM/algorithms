/* Given an integer n, return the least number of perfect square numbers that sum to n.
 Input - n = 12 
 Output - 3
 Explanation - 12 = 4 + 4 + 4
*/

#include<bits/stdc++.h>
using namespace std;

int numSquares(int n) {
        
    vector<int>dp(n+1,INT_MAX-1);
    dp[0]=0;
    dp[1]=1;
    
    for(int i=2;i<=n;i++) {
        for(int j=1;j*j<=i;j++) {
            dp[i]=min(dp[i],dp[i-j*j]+1);
        }
    }
    
    return dp[n];
}

int main() {
    int n;
    cin>>n;

    cout<<"Result = "<<numSquares(n)<<endl;
    return 0;
}