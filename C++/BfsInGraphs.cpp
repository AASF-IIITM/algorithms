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
void bfs(vector<int> graph[],int v,int start)
{
    int visited[v];
    for(int i=0;i<v;i++)
        visited[i]=0;
    queue<int> q;
    q.push(start);
    visited[start]=1;
    while(!q.empty())
    {
        int current = q.front();
        q.pop();
        cout<<current<<" ";
        for(auto itr=graph[current].begin();itr<graph[current].end();itr++)
        {
            if(!visited[*itr])
            {
                visited[*itr]=1;
                q.push(*itr);
            }
        }
    }
    cout<<endl;
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
    bfs(graph,v,0);
   
}