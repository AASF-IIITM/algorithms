#include<bits/stdc++.h>
#define REP(i,n) for (int i = 1; i <= n; i++)
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define ll long long int
#define INF 1000000000
#define endl '\n'


using namespace std;

vector<int> ar[100001];
int vis[100001];
int dis[100001];

void dfs(int node, int d )
{
	vis[node] = 1;
	dis[node]=d;
	
	for(int child : ar[node])
	if(!vis[child])
	dfs(child, dis[node]+1);
	
}


int main()
{
	int n , m , a , b;
	cin>>n;
	
	for(int i=1;i<n;i++)
	{
		cin>>a>>b ; 
		ar[a].push_back(b) ; 
		ar[b].push_back(a);
	}
	dfs(1,0);
	int q,ans,minimum=INT_MAX;
	cin>>q;
	while(q--)
	{
		int k;
		cin>>k;
		if(dis[k]<minimum)
		{
			minimum=dis[k];
			ans=k;
		}
		else if(dis[k]==minimum)
		{
			ans=min(ans, k );
		}
		
	}
	cout<<ans<<endl;
	

}

