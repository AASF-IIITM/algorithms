/* Connected Components in an undirected graph 

Problem Statement - We are given a graph with n vertices and m edges.
                    Answer 'q' queries of the form (a,b) - "are the vertices a and b in the same connected component of the graph?"
        
Approach - This is a very trivial application of DSU (Disjoint Set Union) , also referred as Union-Find.
           Although there are other approaches to solve this problem, but this is a nice way to start with DSU.
*/

#include<bits/stdc++.h>
using namespace std;

const int NN = 1e5;
vector<int> size(NN) , parent(NN);

// Path compression to make this function work faster, in O(logn)
int findparent(int x)
{
	if(x==parent[x]) return x;
	
	return parent[x] = findparent(parent[x]);
}

// This is union-by-size
void unionfunction(int x,int y)
{
	x = findparent(x);
	y = findparent(y);
	
	if(x!=y)
	{
		if(size[x]<size[y])
		{
			size[y] += size[x];
			parent[x] = y;
		}
		else
		{
			size[x] += size[y];
			parent[y] = x;
		}
	}
}

int main()
{
	int n,m;
	cin>>n;           	      // No. of vertices
	cin>>m;                   // No. of edges
	
	for(int i=1;i<=n;i++)
	{
		size[i] = 1;          // Size of each component at the beginning is 1
		parent[i] = i;        // parent of each vertex is itself at the beginning
	}
	
	// Taking input for edges
	for(int i=0;i<m;i++)
	{
		int u,v;
		cin>>u>>v;
		
		unionfunction(u,v);
	}
	
	int q;
	cin>>q;                   // No. of queries
	
	for(int i=0;i<q;i++)
	{
		int u,v;
		cin>>u>>v;
		
		// If parents of both vertices are same, they are connected.
		// Else, not connected.
		if(findparent(u) == findparent(v)) cout<<"Yes, they are connected!\n";
		else cout<<"Not connected\n";
	}
	
	return 0;
}
