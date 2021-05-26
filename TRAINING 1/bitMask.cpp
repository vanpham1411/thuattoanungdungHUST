#include<bits/stdc++.h>

using namespace std;

int m,n;

bitset<32> ip;

void input(){
	cin>>m;
	int a;
	for(int i = 0; i < m; i++){
		cin>>a;
		ip.set(a);
	}
	cin>>n;
		
}
int process(){
	int b;
	for(int i = 0; i< n; i++ ){
		cin>>b;
		if(!ip.test(b)) return 0;
	}
	return 1;
}

int main(){
	input();
	if(process() == 1) cout<<"1";
	else cout<<"0";
	return 0;
}
