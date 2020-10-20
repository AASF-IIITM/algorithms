#include <bits/stdc++.h>

using namespace std;

typedef long long int lld;

lld N=1000000;
lld seive[1000006];
void seivefn() 
{   
    
     for(lld i=1;i<=N;i++) {
          seive[i]=i;
        }
     for(lld i=2;i<=N;i++) {
        if(seive[i]==i) {
            for(lld j=i;j<=N;j+=i) {
                
                seive[j]*=(i-1);
                seive[j]/=i;
            }
        }
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
  cout<<seive[n];
   
}
