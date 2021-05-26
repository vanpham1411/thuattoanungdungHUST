#include<bits/stdc++.h>

using namespace std;

int n,k;
const int N = 2002;
int c[1001][N];

int C(int k, int n){
	if(c[k][n] != 0) return c[k][n];
	if(k == n || k == 0) {
		c[k][n] = 1;
	}
	else{
		c[k][n] = (C(k-1,n-1) + C(k,n-1)) % (1000000007);
	}
	return c[k][n] ;
}

int main(){
	cin>>k>>n;
	if(k > n/2) cout<<C(n-k,n);
	else cout<<C(k,n);
}
