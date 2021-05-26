#include<bits/stdc++.h>

using namespace std;

const int N = 1e5+1;
int n,m;
int p[N];
int r[N];
struct Edge{
	int u;
	int v;
	int w;
	Edge(int _u, int _v, int _w){
		u = _u;
		v = _v;
		w = _w;
	}
};

bool cmp(Edge a, Edge b){
	return a.w < b.w;
}

vector<Edge> E;

void makeSet(int x){
	p[x] = x;
	r[x] = 0;
}

int find(int x){
	if(p[x] != x) p[x] = find(p[x]);
	return p[x];
}

void unify(int ri,int r2){
	if()
}

void input(){
	cin>>m>>n;
	for(int i = 0; i<m;i++){
		int _u,_v,_w;
		cin>>_u>>_v>>_w;
		E.push_back(Edge(_u,_v,_w));
	}
	sort(E.begin(),E.end(),cmp);
}


int main(){
	input();
}



//chi can quan tam den p cua goc
