#include<bits/stdc++.h>

using namespace std;
int n;
const int N = 1e6+1;

int a[N],s[N],ans;

int main(){
	cin>>n;
	for(int i = 0; i<n;i++) cin>>a[i];
	s[0] = a[0];
	ans = s[0];
	for(int i = 1; i<n;i++){
		if(s[i-1] > 0) s[i] = a[i]+s[i-1];
		else s[i] = a[i];
		ans = max(ans,s[i]);
	}
	
	cout<<ans;
}
