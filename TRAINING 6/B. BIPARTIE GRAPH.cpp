#include<bits/stdc++.h>

using namespace std;

const int N = 100001;
int n,m;
int v[N];
int e[N];
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
}

bool BFS(int u){
	if(visited[u] == 0){
		visited[u] = 1;
		q.push(u);
		int nb = 1;
		int tmp= 0;
		while(!q.empty()&& nb >0){
			int x = q.front();
			q.pop();
			for(int i = 0; i<arc[x].size();i++){
				int dinh = arc[x][i];
				if(visited[dinh] == visited[x]) return false;
				else if(visited[dinh] == 0) {
					visited[dinh] = -visited[x];
					tmp++;
				}
			}
			
			nb--;
			if(nb == 0) nb = tmp;
		}
	}
	return true;
}

int main(){
	input();
	for(int i = 1; i<=n;i++){
		if(visited[i] == 0)
			if(BFS(i) == false){
				res= 0;
				break;
			}
	}
	if(res== 0) cout<<"0";
	else cout<<"1";
}
