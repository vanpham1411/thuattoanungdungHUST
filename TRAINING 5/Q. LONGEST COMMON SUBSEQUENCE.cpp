#include<bits/stdc++.h>

using namespace std;

const int LIMIT = 10001;

int n,m;

int x[LIMIT],y[LIMIT];
int s[LIMIT][LIMIT];

void input(){
	cin>>n>>m;
	for(int i = 1; i<=n;i++) cin>>x[i];
	for(int i = 1; i<=m;i++) cin>>y[i];
}

int main(){
	input();
	
	for(int i = 1; i<=n;i++){
		for(int j = 1; j<=m;j++){
			if(x[i] == y[j]) s[i][j] = s[i-1][j-1]+1;
			else s[i][j] = max(s[i][j-1],s[i-1][j]);
		}
	}
	cout<<s[n][m];
}
