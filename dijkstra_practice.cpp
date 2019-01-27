#include <bits/stdc++.h>
#define Mem0(arr) memset(arr,0,sizeof(arr))
#define Mem1(arr) memset(arr,1,sizeof(arr))
#define Dout(v) cout<<"D: "<<v<<endl
#define Dout2(v,y) cout<<v<<" "<<y<<endl
using namespace std;

vector<int> addj[1000];
int cost[1000][1000];
int dist[1000];
int visit[1000];
int par[1000];
vector<int> path;

void dijkstra(pair<int,int> src){
    priority_queue< pair<int,int>, vector<pair<int,int> >, greater< pair<int,int> > > pq;
    pq.push(src);
    dist[1] = 0;
    par[1] = -1;
    while(!pq.empty()){
        pair<int,int> front = pq.top();
        pq.pop();
        int d = front.first;
        int t = front.second;
        visit[t] = 1;
        for(int i=0;i<addj[t].size();i++){
            if(d + cost[t][addj[t][i]] < dist[addj[t][i]]){
                dist[addj[t][i]] = d + cost[t][addj[t][i]];
                par[addj[t][i]] = t;//array for storing sortest path
                pq.push(make_pair(dist[addj[t][i]],addj[t][i]));
            }
        }
    }
}

void graphAdd(int n,int e){
    cout<<"Sequantaly add edges and edges cost..\n";
    for(int i=0;i<e;i++){
        int x,y,c;
        cin>>x>>y>>c;
        addj[x].push_back(y);
        addj[y].push_back(x);
        cost[x][y] = c;
        cost[y][x] = c;
    }
    for(int i=1;i<=n;i++){
        dist[i] = INT_MAX;
    }
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int node,edges;
    cout<<"Enter Node and Edges number: ";
    cin>>node>>edges;
    graphAdd(node,edges);
    cout<<"Just began Dijkstra...\n";
    memset(visit,0,sizeof(visit));
    dijkstra(make_pair(0,1));
    cout<<"Let's show shortest path and distance cost\n";
    cout<<"Shortest path\n";
    for(int i=5;i!=-1;i=par[i]){
        path.push_back(i);
    }
    for(int i = path.size()-1;i>=0;i--){
        cout<<path[i]<<" ";
    }
    cout<<endl;
    cout<<"Distance of all node from source.\n";
    for(int i=1;i<=node;i++){
        cout<<"Distance of node "<<i<<" is "<<dist[i]<<"."<<endl;
    }
    return 0;
}
