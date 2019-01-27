#include <bits/stdc++.h>
using namespace std;
int lebel[1000];
bool visited[1000];
vector<int> addj[1000];

int BFS(int s){

	int value;
	list<int> queue;
	queue.push_back(s);
	visited[s]=true;
	vector<int>::iterator i;

	while(!queue.empty()){
		value = queue.front();
		cout<<value<<" ";
		queue.pop_front();

		for(i = addj[s].begin(); i != addj[s].end(); i++){
			if(!visited[*i]){
				visited[*i]=true;
				queue.push_back(*i);
				lebel[*i]=lebel[s]+1;
			}
		}
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
	BFS(s);


	cout<<"\nLebel is: \n";
	for(int i=1;i<=node;i++){
		cout<<"Node "<<i<<": "<<lebel[i]<<endl;
	}

	return 0;
}
