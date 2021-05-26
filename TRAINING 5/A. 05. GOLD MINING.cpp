#include<bits/stdc++.h>

using namespace std;

const int N = 1000000;
int n,l1,l2;
int a[N];
int s[N];
int ans;

void input(){
	cin>>n>>l1>>l2;
	for(int i = 0; i<n;i++){
		scanf("%d",&a[i]);
	}
}

int main(){
	input();
	ans = a[0];
	s[0] = a[0];
	for(int i = 1;i<n;i++){
		s[i] = a[i];
		for(int j = l1;j<=l2;j++){
			if((i-j)>=0){
				s[i] = max(s[i],a[i]+s[i-j]);
			}
		}
		ans = max(ans,s[i]);
	}
	cout<<ans;
	
}
