#include<bits/stdc++.h>

using namespace std;

const int limit = 1001;

int n,k1,k2;
int cnt;
int ans = 0;



void TRY(int k,int i,int l){	
	if(k == n){
		if(l == 0 || l>=k1) cnt++;
	}
	else if(l<n){
		if(l>= k1) TRY(k+1,0,0);
		if(l<k2) TRY(k+1,1,l+1);
	}
}

int main(){
	cin>>n>>k1>>k2;
	TRY(1,0,0);
	TRY(1,1,1);
	cout<<cnt;
}
