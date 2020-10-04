// C++ program to implement Depth First Search(DFS)

#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
int cost[100][100],i,j,k,n,stk[100],top,v,visit[100],visited[100];
int main()
{
    int m;
    cout <<"Enter total no of vertex:";
    cin >> n;
    cout <<"Enter the no of edges:";
    cin >> m;
    for(k=1; k<=m; k++)
    {
        cout << "Edge "<<k<<"  ";
        cin >>i>>j;     //Enter the edges between nodes ex. 1 2, 1 3
        cost[i][j]=1;
    }
    cout <<"Enter initial vertex to traverse from:";
    cin >>v;
    cout <<"DFS order of visited vertex are:";
    cout << v <<" ";
    visited[v]=1;
    k=1;
    while(k<n)
    {
        for(j=n; j>=1; j--)
            if(cost[v][j]!=0 && visited[j]!=1 && visit[j]!=1)
            {
                visit[j]=1;
                stk[top]=j;
                top++;
            }
        v=stk[--top];
        cout<<v << " ";
        k++;
        visit[v]=0;
        visited[v]=1;
    }
    return 0;
}
