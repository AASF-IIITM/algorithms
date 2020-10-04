#include<bits/stdc++.h>
#define REP(i,n) for (int i = 1; i <= n; i++)
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
#define INF 1000000000
#define endl '\n'

 
using namespace std;
vi ar[10001];
int in[10001];
vi res;
 
bool Kahns(int n)
{
	priority_queue<int,vi,greater<int> > pq;
 
	REP(i , n) if(in[i] == 0) pq.push(i);
 
	while(!pq.empty())
	{
		int curr = pq.top();
		res.pb(curr);
		pq.pop();
 
		for(int child : ar[curr])
		{
			in[child]--;
			if(in[child] == 0)
			pq.push(child);
		}
	}
 
	return res.size() == n;
}
 
int main()
{
	int n , x , y , m;
	cin>>n>>m;
 
	REP(i , m) cin>>x>>y , ar[x].pb(y) , in[y]++;
 
	if(!Kahns(n))
	cout<<"Top Sort Not possible";
	else
	{
		for(int node : res)
		cout<<node<<" ";
	}
}
