#include<bits/stdc++.h>

using namespace std;

const int N = 20001;
int n, m,M;
int a[N];
int cnt;

int main(){
	cin>>n>>m>>M;
	
	for(int i = 0; i<n; i++){
		scanf("%d",&a[i]);
	}
	
	for(int i = 0; i<n; i++){
		int s = 0;
		for(int j = i;j<n;j++){
			s += a[j];
			if(s >=m && s <= M) cnt++;
		}
	}
	cout<<cnt;
}
