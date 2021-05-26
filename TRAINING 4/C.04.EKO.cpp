#include<bits/stdc++.h>

using namespace std;

const int N = 1e6+1;
int n,m;
long long a[N];
long long w[N];
long long weight;

long long big, small, mid;
void input(){
	big = 0;
	cin>>n>>m;
	for(int i = 0; i<n;i++){
		scanf("%d",&a[i]);
		big = max(big,a[i]);
	}
	small = 0;
	
}

int process(){
	while(small<=big){
		weight = 0;
		mid = (big+small)/2;
	//	if(mid == small) return mid;
		for(int i = 0; i<n;i++){
			w[i] = (a[i] >mid) ? (a[i] - mid) : 0;
			weight +=  w[i];
			
		}
		if(weight == m) return mid;
		if(weight > m) small = mid;
		else big = mid;
	}
	return small;
}

int main(){
	input();
	cout<<process();
}

//loi sai: 
//gia tri cua cac bien la long long
//truong hop khong co gia tri mid de chat vua du m met go:
/*
big = 36, small = 35 mid = 35
weight > m -> small = mid: lap vo han
*/

