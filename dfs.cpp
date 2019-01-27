#include <bits/stdc++.h>
using namespace std;
int lebel[1000];
int visited[1000];
vector<int> addj[1000];

void dfs(int s){
    if(visited[s] == 1)
		return;

    visited[s] = 1;
	cout<<s<<" ";
    for(int i = 0;i<addj[s].size();i++){
		dfs(addj[s][i]);
	}
}

void graphStore(int edge){
	int s,d;
	for(int i=1;i<=edge;i++){
		cin>>s>>d;
		addj[s].push_back(d);
		addj[d].push_back(s);
	}
}

int main(){
	int node,edge,i,j;
	cout<<"How many node and edge have? ";
	cin>>node>>edge;
	int s;
	cout<<"At first store graph\n";
	graphStore(edge);
	cout<<"Sourse is ";
	cin>>s;
	cout<<"Nodes: ";
	memset(visited,0,sizeof visited);
	dfs(s);
	cout<<endl;

	return 0;
}
