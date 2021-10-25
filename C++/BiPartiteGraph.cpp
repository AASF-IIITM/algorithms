#include<bits/stdc++.h>
using namespace std;
#define ll long long int

bool dfs(int start, vector<int>& color, vector<int> adj[], int current_color) {
        
    color[start]=current_color;
    
    for(int i=0;i<adj[start].size();i++) {
        if(color[adj[start][i]]==-1) {
            if(dfs(adj[start][i],color,adj,1-current_color)==false) return false;
        }else if(color[adj[start][i]]==current_color) return false;
    }
    
    return true;
}

bool isBipartiteGraph(vector<int>adj_list[], int n) {
    vector<int>color(n,-1);
    for(int i=0;i<n;i++) {
        if(color[i]==-1) {
            if(dfs(i,color,adj_list,0)==false) return false;
        }
    }
    
    return true;
}

int main() {
    int n,e;
    cout<<"Enter the number of vertices"<<endl;
    cin>>n;
    cout<<"Enter the number of edges"<<endl;
    cin>>e;

    vector<int>adj_list[n];
    for(int i=0;i<e;i++) {
        int u,v;
        cin>>u>>v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    for(int i=0;i<adj_list[0].size();i++) {
        cout<<adj_list[0][i]<<" ";
    }
    cout<<endl;

    bool isBipartite = isBipartiteGraph(adj_list,n);

    if(isBipartite) cout<<"Bi-partite graph"<<endl;
    else cout<<"Not Bi-partite graph"<<endl;

    return 0;
}