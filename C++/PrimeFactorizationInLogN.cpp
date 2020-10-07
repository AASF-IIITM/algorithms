#include <bits/stdc++.h>

using namespace std;

typedef long long int lld;

lld N=1000000;
lld seive[1000006];
void seivefn() 
{   
    memset(seive,-1,sizeof(seive));
    for(lld i=2;i<=N;i++) {
        if(seive[i]==-1) {
            for(lld j=i*i;j<=N;j+=i) {
                if(seive[j]==-1)
                seive[j]=i;
            }
        }
    }
    for(lld i=2;i<=N;i++) {
        if(seive[i]==-1) 
        seive[i]=i;
    }
}


int main()
{

 ios_base::sync_with_stdio(false);
 cin.tie(NULL);  
#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
#endif
seivefn();
  lld n;
  cin>>n;
  while(seive[n]!=-1) {
      cout<<seive[n]<<" ";
      n/=seive[n];
  }
   
}
