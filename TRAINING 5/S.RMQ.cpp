#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+1;

int a[N];
int n,m;
typedef pair<int, int> pairs;
vector< pair<long long,long long > > r;//request
vector< pair<long long ,long long> > v;
long long ans;
bool cmp(pair<long long,long long>a, pair<long long,long long>b){
	return a.second <b.second;
}

int main(){
	cin>>n;
	for(int i = 0; i<n;i++ ) {
		long long x;
		scanf("%lld",&x);
		v.push_back(make_pair(i,x));
	}
	sort(v.begin(),v.end(),cmp);
	cin>>m;
	for(int i = 0; i<m;i++){
		long long x,y;
		scanf("%lld%lld",&x,&y);
		r.push_back(make_pair(x,y));
	}
	
	for(int i = 0; i<m;i++){
		for(int j = 0; j<n;j++){
			if(v[j].first >= r[i].first && v[j].first <= r[i].second){
				ans+= v[j].second;
				break;
			}
		}
	}
	
	cout<<ans;
	
	return 0;
}
