/* 

Author - Sayantan Banerjee (2018IMT-093)

Reachability between two nodes in a Undirected Graph

Problem Statement - We are given a graph with n vertices and m edges.
                    Return if a particular node can be reachable from another node.
                    
Output - Return 1 if reachable. 0 if not.
        
Approach - Implementation done here by using DFS in Graph.
*/


#include <iostream>
#include <vector>

using std::vector;
using std::pair;

vector<int> visited(1003, 0);

bool over = false;

void Explore(vector<vector<int> > &adj, int v, int y){
	if(over)
		return;
	visited[v] = 1;
	for(int i =0 ; i < adj[v].size() ; i++){
		if(visited[adj[v][i]] == 0){
			if(adj[v][i] == y){
				over = true;
				return;
			}else{
				Explore(adj, adj[v][i], y);	
			}
		}
	}
}


int reach(vector<vector<int> > &adj, int x, int y) {
  //write your code here
  Explore(adj, x, y);
  if(over)
  	return 1;
  else
	return 0;
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
  int x, y;
  std::cin >> x >> y;
  std::cout << reach(adj, x - 1, y - 1);
}
