#include<bits/stdc++.h>

using namespace std;

const int N = 1e5+1;

const int INF = 1e9;
typedef pair<int, int> pi;
struct Arc{
	int node;
	int w;
	Arc(int _node, int _w){
		node = _node;
		w = _w;
	}
};

int n,m;
int s,t;
vector<Arc> A[N];

int d[N];



void input(){
	cin>>n>>m;
	for(int i = 0; i<m;i++){
		int _u,_v,_w;
		scanf("%d%d%d",&_u,&_v,&_w);
		A[_u].push_back(Arc(_v,_w));
		
	}
	cin>>s>>t;
}


void solve(){
	for(int i = 1; i<=n;i++) d[i] = INF;
	priority_queue< pi, vector<pi>, greater<pi> > pq;
	
	d[s] = 0;
	pq.push(make_pair(d[s],s));
	
	while(!pq.empty()){
		pair<int,int> p = pq.top(); pq.pop();
		int v = p.second;
		if(v == t) break;
		
		for(int i = 0; i< A[v].size();i++){
			Arc a = A[v][i];
			int u = a.node;  int w = a.w;
			if(d[v] + w < d[u]){
				d[u] = d[v]+w;
				pq.push(make_pair(d[u],u));
			}
		}
		
	} 
}


int main(){
	input();
	solve();
	if(d[t]== INF) d[t] = -1;
	cout<<d[t];
}
