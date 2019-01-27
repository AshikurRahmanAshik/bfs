#include<bits/stdc++.h>
using namespace std;

int visited[1010];
int level[1010];

vector<int>adj[1010];

int bfs(int s)
{
    int value;

    list<int>queue;
    queue.push_back(s);

    visited[s] = true;
    vector<int>::iterator i;

    while(!queue.empty())
    {
        value = queue.front();
        cout<<value<<" ";
        queue.pop_front();

        for(i=adj[s].begin(); i!=adj[s].end(); i++)
        {
            if(!visited[*i])
            {
                visited[*i]=true;
                queue.push_back(*i);
                level[*i] = level[s] + 1;
            }
        }
    }
}

void graphStore(int edge)
{
    int s, d;

    for(int i=1; i<=edge; i++)
    {
        cin>>s>>d;
        adj[s].push_back(d);
        adj[d].push_back(s);
    }
}

int main()
{
    int node, edge, s, i, j;

    cout<<"How many node and edge have ? "<<endl;
    cin>>node>>edge;

    cout<<"At first store Graph : "<<endl;
    graphStore(edge);

    cout<<"Source is : "<<endl;
    cin>>s;

    bfs(s);

    cout<<endl;
    cout<<"level is : "<<endl;
    for(i=1; i<=node; i++)
        cout<<"Node : "<<i<<" : "<<level[i]<<endl;

    return 0;
}

