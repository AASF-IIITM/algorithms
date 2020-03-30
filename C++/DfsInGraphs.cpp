#include<bits/stdc++.h>
using namespace std;
void addundiredge(vector<int> graph[],int start,int end)
{
    graph[start].push_back(end);
    graph[end].push_back(start);
}
void adddiredge(vector<int> graph[],int start ,int end)
{
    graph[start].push_back(end);
}
void printgraph(vector<int> graph[],int numberofvertex)
{
    for(int i=0;i<numberofvertex;i++)
    {  
        cout<<"edge->"<<i<<":";
        for(auto itr=graph[i].begin();itr<graph[i].end();itr++)
            cout<<"->"<<*itr;
        cout<<endl;
    }
    cout<<endl;
}

void dfs(vector<int> graph[],int v,int start)
{
    int visited[v];
    for(int i=0;i<v;i++)
    visited[i]=0;
    stack<int> s;
    s.push(start);
    while(!s.empty())
    {
        int current=s.top();
        s.pop();
        if(!visited[current])
        {
            cout<<current<<" ";
            visited[current]=1;
        }
        for(auto itr=graph[current].begin();itr<graph[current].end();itr++)
        {
            if(visited[*itr]==0)
                s.push(*itr);
        }
    }
}

int main(){
    int v=4;
    vector<int> graph[v];
    adddiredge(graph,0,1);
    adddiredge(graph,0,2);
    adddiredge(graph,1,2);
    adddiredge(graph,2,0);
    adddiredge(graph,2,3);
    adddiredge(graph,3,3);
    printgraph(graph,v);
    dfs(graph,v,0);
   
}