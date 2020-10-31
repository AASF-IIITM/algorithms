/* 

Author - Sayantan Banerjee (2018IMT-093)

Cycle Detection in Directed Graph
        
Approach - Implemented through DFS of each unvisited node. 
           And also current visited nodes are tracked in order to check if some path points back to another node of current path, 
		   determining there is a cycle.
*/

#include <iostream>
#include <vector>

using std::vector;
using std::pair;

bool cycle = false;

void DFS(int v, vector<vector<int> > &adj, vector<bool> &visited , vector<bool> &curvisited){
    visited[v] = 1;
    curvisited[v] = 1;
    for(int j = 0 ; j < adj[v].size(); j++){
        if(curvisited[adj[v][j]] == 1){
            cycle = true;
            return;
        }else{
            if(visited[adj[v][j]] == false)
                DFS(adj[v][j], adj, visited, curvisited);
        }
    }
    curvisited[v] = 0;
    if(cycle)
        return;
}

int acyclic(vector<vector<int> > &adj, int numCourses) {
  vector<bool> visited(numCourses, false);
  vector<bool> curvisited(numCourses, false);
  for(int i=0 ; i < numCourses && !cycle ; i++){
        if(visited[i] == false)
            DFS(i, adj, visited, curvisited);
  }
  if(cycle)
    return true;
  else
    return false;
}

int main() {
  cycle = false;
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  std::cout << acyclic(adj, n);
}
