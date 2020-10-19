#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll Kadane(ll arr[],ll n)
{
	ll best=0,sum=0;
	for(ll k=0;k<n;k++)
	{
       sum=max(arr[k],sum+arr[k]);
       best=max(best,sum);
	}
	return best;
}
int main()
{
   /*#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   #endif*/
   ll n;
   cin>>n;
   ll arr[n];
   for(ll i=0;i<n;i++)
   cin>>arr[i];
   cout<<Kadane(arr,n);
   return 0;
}