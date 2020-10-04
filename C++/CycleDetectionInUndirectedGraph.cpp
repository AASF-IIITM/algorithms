bool visited[maxn];
bool dfs(int current, int parent) {
	visited[current]=1;
	for(int i:adj[current]) {
		if(visited[i]==0) {
			if(dfs(i, current)==true) {
				return true;
			}
		}
		else {
			if(i!=parent) {
				return true;
			}
		}
	}
	return false;
}
