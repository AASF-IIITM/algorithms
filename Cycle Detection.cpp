bool visited[maxn];
bool dfs(ll current, ll parent) {
	visited[current]=1;
	for(ll i:adj[current]) {
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
