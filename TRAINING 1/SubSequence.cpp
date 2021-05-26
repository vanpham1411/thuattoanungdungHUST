#include<bits/stdc++.h>

using namespace std;
int s;
long long a[1000000];
long long b[1000];
void input(){
	cin>>s;
	for(int i = 0; i < s; i++){
		cin>>a[i];
	}
	
	for(int i = 0; i < 1000; i++){
		b[i] = 0;
	}
}

void process(){
	long long  d = 1000000007;
	long long  m = 0;
	
	int fn = s/1000;
	
	int ft = s%1000;
	for(int i = 0; i < fn; i++){
		int m = 1000*i;
		for(int j = 0; j < 1000; j++){
			b[i ] = b[i] + a[m + j]%d;
		}
	}
	if(ft >0){
		
		int h = 1000*fn;
		for(int i = 0; i < ft; i++){
		b[fn] = b[fn] + a[h+ i] %d;
		
	}
	fn++;
	
	}
	for(int i = 0; i < fn; i++){
		m =  m + b[i] %d;	}
		m = m%1000000007;
	cout<<m;
}

 void process2(){
 	long long m;
 	long long d= 1000000007;
 	for(int i = 0; i< s; i++){
 		m = m + a[i]%d;
	 }
	 m = m
	 cout<<m;
	
}

int main(){
	
	input();
	
	process();
	return 0;
}
