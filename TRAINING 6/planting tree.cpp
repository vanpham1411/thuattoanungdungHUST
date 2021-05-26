#include<bits/stdc++.h>

using namespace std;

int n;
int max_t;
int cnt = 0;
int res;
int a[100000];

bool cmp(int a, int b){
	return a>b;
}
int main(){
	cin>>n;
	for(int i = 0; i<n;i++){
		scanf("%d",&a[i]);
	}
	sort(a,a+n,cmp);
	for(int i = 0; i<n;i++){
		max_t = max_t > a[i]+1+i ? max_t :a[i]+1+i;
	}
	max_t ++;
	cout<<max_t;
}
