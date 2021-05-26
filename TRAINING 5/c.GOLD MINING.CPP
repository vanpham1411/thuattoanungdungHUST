#include<bits/stdc++.h>

using namespace std;

const int N = 1000000;
int n,l1,l2;
int a[N];
int s[N];
int ans;
priority_queue<pair<int,int>> pq;

void input(){
	cin>>n>>l1>>l2;
	for(int i = 0; i<n;i++){
		scanf("%d",&a[i]);
	}
}

int main(){
	input();
	ans = a[0];
	for(int i = 0; i<l1;i++){
		s[i] = a[i];
		
	}
	pq.push(make_pair(a[0],0));
	ans = pq.top().first;
	int cnt = 0;
	for(int i = l1; i<n;i++){
		while(pq.top().second <i-l2) pq.pop();
		s[i] = a[i] + pq.top().first;
		ans = max(ans,s[i]);
		//cout<<"s["<<i<<"]= "<<s[i];
		cnt++;
		pq.push(make_pair(s[cnt],cnt));
		
	}
	
	cout<<ans;
	
}
