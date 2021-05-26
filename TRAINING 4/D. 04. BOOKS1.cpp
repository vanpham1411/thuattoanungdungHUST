#include<bits/stdc++.h>

using namespace std;
int n,k,m;
const int N = 501;
int b[N];
long long w[N],tmp[N];
long long p[N];
long long max_p;
long long ans;
long long low, high,mid;

void input(){
	cin>>m>>k;
	for(int i = 1; i<=m;i++){
		scanf("%lld",&p[i]);
		high = high+ p[i];
	}
}

bool check(long long limit){
	int pos = 1;
	for(int i = 1; i<=m;i++ ){
		if(tmp[pos] +p[i] <= limit) tmp[pos] += p[i];
		else{
			pos++;
		}
		if(pos > k) return true;
	}
	return pos >k;
}



