#include<bits/stdc++.h>

using namespace std;

int n;
long long a[1000001];
bool visited0[1000001];
bool visited1[1000001];
int ans = 0;
int s[1000001];

bool check(long long a,long long b){
	if(a<0 && b<0) return false;
	if(a>0 && b>0) return false;
	
	a = a >0 ? a: -a;
	b = b>0 ? b :-b;
	if(a >b ) return true;
	else return false;
}

int main(){
	cin>>n;
	for(int i = 1; i<=n;i++){
		cin>>a[i];
	}
	for(int i = 1;i<=n;i++){
		s[i] = 1;
		for(int j = 1;j<n;j++){
			if( check(a[i],a[j]) ) s[i] = max(s[i],s[j]+1); 
		}
		ans = max(ans,s[i]);
	}
	cout<<ans;
	
}
