#include<bits/stdc++.h>

using namespace std;

int n,b;
int a[1000000];
int amax[1000000], re_max[1000000];

void input(){
	cin>>n>>b;
	for(int i = 1; i <=n; i++ ){
		cin>>a[i];
	}
	a[0] = 0;
	a[n+1] = 0;
}
void process(){
	int re = -1;
	int tmp;
	amax[0] = 0;
	re_max[n+1] = 0;
	for(int i = 1; i <= n ; i++){
		if(a[i] > amax[i-1]) amax[i] = a[i];
		else amax[i] = amax[i-1];
	}
	
	for(int i = n; i >= 1; i--){
		if(a[i] > re_max[i+1]) re_max[i] = a[i];
		else re_max[i] = re_max[i+1];
	}
	
	int t, re_t;
	for(int i = 2; i <=n - 1;i++){
		t = amax[i-1] - a[i];
		re_t = re_max[i+1] - a[i];
		if(t>= b && re_t >= b && t+re_t >re) re = t+re_t;
	}
	cout<<re;
}
int main(){
	input();
	process();
	return 0;
}
