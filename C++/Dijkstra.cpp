#include<bits/stdc++.h>
using namespace std;

vector< pair<int,int> > ar[100001];


int main()
{
	int n,m;
	cin>>n>>m;
	
	while(m--)
	{
		int a,b,w;
		cin>>a>>b>>w;
		ar[a].push_back({b,w});
		ar[b].push_back({a,w});
	}
	priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
	vector<int> dist(n+1,1000000000);
	pq.push({1,0});
	dist[1]=0;
	
	while(!pq.empty())
	{
		int cur=pq.top().first;
		int cur_dist=pq.top().second;
		pq.pop();
		for(pair<int,int> edge : ar[cur])
		{
			if( cur_dist + edge.second < dist[edge.first])
			{
				dist[edge.first]= edge.second+ cur_dist;
				pq.push({edge.first,dist[edge.first]});
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(dist[i]==1000000000)
		cout<<"-1"<<" ";
		else
		cout<<dist[i]<<" ";
	}
}
