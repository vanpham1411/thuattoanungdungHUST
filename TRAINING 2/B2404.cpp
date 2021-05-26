#include<bits/stdc++.h>

using namespace std;

const long long N = 10001;

long long n, k;
typedef pair<long,long> pairs;

vector< pairs> x,y;

long long ans;

bool cmp( pairs a, pairs b){
	return a.first > b.first;
}

void input(){
	cin>>n>>k;
	
	for(int i = 0; i<n;i++){
		long long a,b;
		cin>>a>>b;
		
		if(a >0) x.push_back(make_pair(a,b));
		else y.push_back(make_pair(-a,b));
			
	}
	sort(x.begin(),x.end(),cmp);
	sort(y.begin(),y.end(),cmp);	
}

void process(){
	long long s = 0;
	long long d= 0;
	int sz = x.size();
	for(int i = 0; i<sz;i++){
//		cout<<"for"<<i<<endl;
		if(d == 0) d = x[i].first;
		s+= x[i].second;
//		cout<<"i= "<<i<<" s "<<s<<" d: "<<d<<" = "<<x[i].first<<endl;
		if(s>= k){
			long long t = s/k;
			ans += d + x[i].first*(t-1);
			s= s%k;
			if(s == 0) d = 0;
			else d = x[i].first;
//			cout<<"ans = "<<ans<<endl;
		}
	}
	if(s >0 ) {
		if(d >0) ans+= d;
	}
//	cout<<"x "<<ans<<endl;
	
	s = 0; 
	d = 0;
	sz = y.size();
//	cout<<"y size "<<sz<<endl;
	for(int i = 0; i<sz;i++){
		if(d == 0) d = y[i].first;
		s+= y[i].second;
		if(s>= k){
			long long t = s/k;
			ans += d+y[i].first*(t-1);
			s= s%k;
			if(s == 0) d = 0;
			else d = y[i].first;
		}
	//cout<<"mang am "<<ans<<" d = "<<d<<"s = "<<s<<endl;	
	}
	if(s >0 ) {
		if(d >0) ans+= d;
	}
	ans = ans*2;
	
}

int main(){
	input();
	process();
	cout<<ans;
}

