#include<bits/stdc++.h>

using namespace std;

const int N = 101;
int cnt;
int n,m;

int a[N];

void input(){
	cin>>n>>m;
	for(int i = 0; i<n; i++) cin>>a[i];
}

void TRY(int k,int _s){
	for(int v = 1; v<= _s/a[k];v++ ){
		if((k == n-1 ) && ((_s - v*a[k]) == 0) ) cnt++;
		else if( k<n-1 ) TRY(k+1,_s - v*a[k]);
	}
}

int main(){
	input();
	TRY(0,m);
	cout<<cnt;
}

