#include<bits/stdc++.h>

using namespace std;

const int N = 3001;
const int K = 101;

int n,k;
int a[N], c[N];
int w[N][K];
int ans;

void input(){
	cin>>n>>k;
	for(int i = 1; i<=n;i++){
		cin>>c[i];
	}
	for(int i= 1; i<=n;i++){
		cin>>a[i];
	}
}

int main(){
	input();
	
	w[1][1] = c[1];
	ans = w[1][1];
	for(int i = 2;i<=n;i++){
		for(int u = 1;u<=k;u++){
			for(int v=1;v<i;v++){
				if(i-v <= a[v] && w[v][u] >0)  w[i][u+1] = max(w[i][u+1],w[v][u]+c[i]);
			}
		}
	}
	
	for(int i = 1;i<=k+1;i++) ans = max(ans,w[n][i]);
	
//	for(int i = 1; i<=n;i++){
//		for(int j = 1;j<=k+1;j++){
//			cout<<w[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	cout<<ans;	
}

