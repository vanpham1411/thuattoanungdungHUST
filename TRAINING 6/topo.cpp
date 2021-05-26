#include<bits/stdc++.h>

using namespace std;

const int N = 1e5+1;

vector<int> A[N];
int d[N];
vector<int> L;
queue<int> q;
int n,m;
void input(){
	cin>>n>>m;
	
	for(int i = 1; i<=m;i++){
		int u,v;
		cin>>u>>v;
		d[v]++;
		A[u].push_back(v);
	}
	for(int i = 1;i<=n;i++) cout<<d[i]<<" ";
	cout<<endl;
}

void TOPO(){
	while(!q.empty()){
		int x = q.front();
		q.pop();
		L.push_back(x);
		for(int i = 0; i< A[x].size();i++){
			int v = A[x][i];
			d[v] = d[v]-1;
			if(d[v] == 0) q.push(v);
		}
	}
}

int main(){
	input();
	for(int i = 1; i<=n;i++){
		if(d[i] == 0) {
//			cout<<i<<endl;
			q.push(i);
		}
	}
	TOPO();
	if(L.size() == n) cout<<"1";
	else cout<<"NULL";
}

//6 11
//1 3
//3 1
//2 1
//2 3
//2 5
//2 6
//4 1
//4 5
//5 1
//6 4
//6 5

