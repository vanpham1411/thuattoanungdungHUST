#include<bits/stdc++.h>

using namespace std;

int n;
int a[10001];
int tmp;
int ans;
int s[10001];

int main(){
	cin>>n;
	for(int i = 0; i<n;i++){
		cin>>a[i];
	}
	s[0] = 1;
	ans = s[0];
	for(int i = 1; i<n;i++){
		s[i] = 1;
		for(int j = 0; j<i;j++){
			
			if(a[j] <a[i]) {
				if(s[i] <s[j]+1) s[i] = s[j] +1;
			}
		}
		ans = ans > s[i] ? ans:s[i] ;
	}
//	for(int i = 0; i<n;i++) cout<<s[i]<<" ";
//	cout<<endl;
	cout<<ans;
}
