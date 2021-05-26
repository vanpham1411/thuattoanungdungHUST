#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;

const int N = 101;
ll n,m;
ll a[11];
vector< pair<ll,ll> > v;
ll w[11];
ll c[501][501];
ll sl = 0;
ll cnt;
ll v_size;

void input(){
	cin>>n>>m;
	for(int i = 0; i<n;i++){
		ll var;
		cin>>var;
		a[var]++;
	}
	
	for(ll i = 10; i>=1; i--){
		if(a[i] >0) v.push_back(make_pair(i,a[i]));
	}
	v_size = v.size();
//	cout<<"v_size: "<<v_size<<endl;
//	for(int j = 0; j<v_size;j++){
//		cout<<"("<<v[j].first<<", "<<v[j].second<<") ";
//	}
}

ll C(ll k,ll n){
	if(c[k][n] != 0) return c[k][n];
	if(n == k || k == 0) {
		c[k][n] = 1;
		return 1;
	}else{
		c[k][n] = C(k,n-1) +C(k-1,n-1);
		return c[k][n]%1000000007;
	}
}

void TRY(ll k,ll s){
	ll max_i = s/v[k].first;
	for(ll i = v[k].second; i<= max_i;i++){
		w[k] = i;
		s -= i*v[k].first;
		if(k == v_size -1 && s== 0 ){
			ll tmp = 1;
//			for(int j = 0; j<v_size;j++){
//				cout<<"("<<v[j].first<<", "<<v[j].second<<") ";
//			}
//			cout<<endl;
//			for(int j = 0; j<v_size;j++){
//				cout<<w[j]<<"	";
//				
//			}
//			cout<<endl;
			for(int j = 0; j<v_size;j++){
//				cout<<j<<": "<<C(v[j].second-1,w[j]-1)<<endl;
				tmp = tmp* C(v[j].second-1,w[j]-1);
				tmp = tmp%1000000007;
			}
			cnt+=tmp;
//			cout<<"cnt = "<<cnt<<endl;
		}else if( k < v_size - 1 && s>0) TRY(k+1,s);
		w[k] = 0;
		s += i*v[k].first;
	}
}

int main(){
	input();
	TRY(0,m);
	cnt = cnt%(1000000007);
	cout<<cnt;
	return 0;
}


