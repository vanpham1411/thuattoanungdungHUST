#include<bits/stdc++.h>

using namespace std;
const int N= 2000000;
int n;
vector< pair <int,int> > v,u;

int w[N],s[N];
int w1[N];
int max_w,p;
int ans = -1;

bool cmp(pair<int,int> a,pair<int,int> b){
	return a.second < b.second;
}
bool cmp1(pair<int,int> a,pair<int,int> b){
	return a.first < b.first;
}
void input(){
	cin>>n;
	int si,ti;
	for(int i = 0; i<n;i++){
		scanf("%d%d",&si,&ti);
		pair<int,int> p = make_pair(si,ti);
		v.push_back(p);
		u.push_back(p);
	}
	sort(v.begin(),v.end(),cmp);
	sort(u.begin(),u.end(),cmp1);
	
	for(int i = 0; i<n; i++){
		w[i] = v[i].second - v[i].first;
	}
}

 int main(){
 	
 	input();
 	p = 0;
 	for(int i = 0; i<n; i++){	
 		while(u[i].first > v[p].second && p <n ) {
 			max_w = max(max_w, w[p]);
 			p++;
		 }
		 s[i] = max_w >0 ? max_w + u[i].second - u[i].first : 0;
		 ans = max(ans,s[i]);
	 }
	 
	 cout<<ans;
 	
 }
