#include<bits/stdc++.h>

using namespace std;

const int N = 100001;
int n,m;
int d[N]; // level of v
int visited[N];
vector<int> arc[N]; //arc[v] is the list if adiacent nodes of v
int res=1;

queue<int> q;

void input(){
	cin>>n>>m;
	for(int i = 0; i<m;i++){
		int a,b;
		cin>>a>>b;
		arc[a].push_back(b);
		arc[b].push_back(a);
	}
	for(int i = 1; i<=n;i++) d[i] = -1;
}

int BFS(int u){
	d[u] = 0;
	q.push(u);
	while(!q.empty()){
		int x = q.front(); q.pop();
		for(int i = 0; i< arc[x].size();i++){
			int v = arc[x][i];
			if(d[v]==-1){
				d[v] = d[x]+1;
				q.push(v);
			}else{
				if((d[v]+d[x]) %2 == 0) {
					return false;
				} 
			}
		}
	}
	return true;
}

int main(){
	input();
	for(int i = 1; i<=n;i++){
		if(d[i] == -1)
			if(BFS(i) == false){
				res= 0;
				break;
			}
	}
	if(res== 0) cout<<"0";
	else cout<<"1";
}
