#include <bits/stdc++.h>
using namespace std;
 
typedef long long  ll;
typedef long double ld;
 
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace __gnu_pbds;
 
typedef tree<ll, null_type,
             less_equal<ll>, rb_tree_tag,
             tree_order_statistics_node_update>
 
    ordered_set;
 
void boost()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
}
 
int main()
{
    boost();
 
    ll i,k,n,c=0,d=0,t,x,y;
    ll l,r,ans,h,f,m,z;
    vector<ll> v;
 
    ordered_set ss;
 
    cin>>n>>k;
    ll a[n];
 
    for(i=0;i<n;i++)
    cin>>a[i];
 
    for(i=0;i<k;i++)
    {
        ss.insert(a[i]);
    }
 
    if(k&1)
    {
 
      auto j=ss.find_by_order((k/2));
      cout<<*j<<" ";
 
    }
 
    else
    {
         z=*ss.find_by_order((k/2));
         z=min(z,*ss.find_by_order((k/2)-1));
         cout<<z<<" ";
 
 
    }
 
 
    for(i=k;i<n;i++)
    {
 
    ss.erase(ss.find_by_order(ss.order_of_key(a[i-k])));
    ss.insert(a[i]);
 
if(k&1)
{
      z=*ss.find_by_order(k/2);
    cout<<z<<" ";
}
 
else
{
     z=*ss.find_by_order(k/2);
         z=min(z,*ss.find_by_order((k/2)-1));
        cout<<z<<" ";
}
 
    }
 
 
return 0;
}