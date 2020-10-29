/* 

Author - Sayantan Banerjee (2018IMT-093)

Number of Connected Components in an undirected graph 

Problem Statement - We are given a graph with n vertices and m edges.
                    Return number of connected components.
        
Approach - Implementation done here by using DFS in Graph.
*/


#include <iostream>
#include <vector>

using std::vector;
using std::pair;

vector<int> visited(1003,0);

void Explore(int v, vector<vector<int> > &adj){
	visited[v] = 1;
	for(int j = 0 ; j < adj[v].size(); j++){
		if(visited[adj[v][j]] == 0){
			Explore(adj[v][j], adj);
		}
	}
}

int number_of_components(vector<vector<int> > &adj, int n) {
  int res = 0;
  for(int i=0 ; i < n ; i++){
  	if(visited[i] == 0){
  		res++;
		Explore(i, adj);	
	}
  }
  return res;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  std::cout << number_of_components(adj, n);
}

