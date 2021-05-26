#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+1;

int n,m;
vector<int> A[N];
int res;
bool visited[N];

void input(){
	cin>>n>>m;
	for(int i = 1; i<=m;i++){
		int u,v;
		cin>>u>>v;
		A[u].push_back(v);
		A[v].push_back(u);
	}
}


void DFS(int x){
	queue<int> q;
	visited[x] = true;
	q.push(x);
	while(!q.empty()){
		int u = q.front(); q.pop();
		for(int i =0; i<A[u].size();i++){
		int v = A[u][i];
		if(visited[v] == false){
			visited[v] = true;
			q.push(v);
		}
	}
	}
}

int main(){
	input();
	for(int i = 1; i<=n;i++){
		if(visited[i] ==  false){
			DFS(i);
			res++;
		}
	}
	cout<<res;
}
