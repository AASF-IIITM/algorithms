#include <bits/stdc++.h>

using namespace std;

const int inf = 1<<29;
const int maxn = 20;

int n;
int dis[maxn+3][maxn+3] = {};
int dp[(1<<maxn)+3][maxn+11] = {};

int solve(int s, int last){
    if (dp[s][last] == 0){
        dp[s][last] = inf;

        if (__builtin_popcount(s) == 1) dp[s][last] = dis[0][last];
        else{
            for(int i = 1;i < n;i++){
                if (i == last) continue;
                if (((1<<i)&s) == 0) continue;
                dp[s][last] = min(dp[s][last], solve(s^(1<<last), i)+dis[i][last]);
            }
        }
    }
    return dp[s][last];
}

int main(){

    cin>>n;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            cin>>dis[i][j];
        }
    }

    cout << solve((1<<n)-1, 0) << endl;

    return 0;
}

/* sample input
    4
    0 20 35 42
    20 0 34 30
    35 34 0 12
    42 30 12 0
*/
