// C++ program to implement BFS in a directed graph
#include <bits/stdc++.h> 
using namespace std; 

vector<bool> v; 
vector<vector<int> > g; 
void edge(int a, int b){                // function to add edge from a to b
	g[a].push_back(b);                                 
} 
void bfs(int u){ 
	queue<int> q; 
	q.push(u); 
	v[u] = true; 
	while (!q.empty()) { 
		int f = q.front(); 
		q.pop(); 
		cout << f << " "; 
		for (auto i = g[f].begin(); i != g[f].end(); i++) { 
			if (!v[*i]) { 
				q.push(*i); 
				v[*i] = true; 
			} 
		} 
	} 
} 
int main() { 
	int n, e; 
	cin >> n >> e;                  // input nmber of nodes and edges 
	v.assign(n, false);             // assigning false to every node
	g.assign(n, vector<int>()); 
	int a, b; 
	for (int i = 0; i < e; i++) { 
		cin >> a >> b; 
		edge(a, b); 
	} 
    int starting_point;
    cin >> starting_point;
    bfs(staring_point);
	return 0; 
} 
