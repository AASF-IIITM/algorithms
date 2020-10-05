#include<bits/stdc++.h>

using namespace std;
typedef long long int lld;

void mcr(string s) {

  lld n=s.size();
  lld arr[n];
  memset(arr,0,sizeof(arr));
  lld r=0,c=0,pos,ma=LONG_LONG_MIN;
  for(lld i=1;i<n;i++) {
    lld mir = 2*c-i;
    if(i<r) {
       arr[i] = min(r-i,arr[mir]);
    }

    while(s[i-arr[i]-1]==s[i+arr[i]+1]) {
           arr[i]++;
    }
    if(c+arr[i]>r){
      c=i;
      r=c+arr[i];
    }
    if(arr[i]>ma) {
      pos=i;
      ma=arr[i];
    }
  }


  lld p=pos-arr[pos];
  lld q=pos+arr[pos];
  string ans="";
  while(p<=q) {
    if(isalpha(s[p]))
      ans+=s[p];
    p++;
  }
  cout<<ans<<endl;
  
}

int main()
{   
   
     #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lld t;
    cin>>t;
    while(t--){
       string s;
       cin>>s;
       string m="%#";
       for(lld i=0;i<s.size();i++) {
         m+=s[i];
         m+="#";
       }
       m+="@";
      mcr(m);
       

    }
    
    return 0; 

}