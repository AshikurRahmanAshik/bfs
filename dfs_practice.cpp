#include<bits/stdc++.h>
using namespace std;

int visited[1010];
int level[1010];

vector<int>adj[1010];

void dfs(int s)
{
    if(visited[s]==1)
        return;

    visited[s] = 1;
    cout<<s<<" ";

    for(int i=0; i<adj[s].size(); i++)
        dfs(adj[s][i]);
}

void graphStore(int edge)
{
    int s,d;

    for(int i=1; i<=edge; i++)
    {
        cin>>s>>d;
        adj[s].push_back(d);
        adj[d].push_back(s);
    }
}

int main()
{
    int node, edge, i, j, s;

    cout<<"How many node and edge have ? "<<endl;
    cin>>node>>edge;

    cout<<"At first store graph "<<endl;
    graphStore(edge);

    cout<<"Source is : "<<endl;
    cin>>s;

    cout<<"Nodes : "<<endl;

    memset(visited, 0, sizeof visited);

    dfs(s);

    return 0;
}
