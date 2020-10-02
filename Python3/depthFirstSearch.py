#Method to print DFS Traversal Of Tree.
def dfs(graph,visited,u):
    visited[u]=True
    print(u," ",end="")
    for i in graph[u]:
        if(visited[i]==False):
            dfs(graph,visited,i)
