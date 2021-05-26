#include<bits/stdc++.h>

using namespace std;

const int N = 1001;
int n, T ,D;
int a[N],t[N];
int w[N][N];
int ans = 0;

void input(){
	cin>>n>>T>>D;
	for(int i = 1; i<=n;i++) cin>>a[i];
	for(int i = 1; i<=n;i++) cin>>t[i];
}

int compute(int i,int j,int _t){
	int res = 0;
	for(int k = 0; k <= _t;k++){
		if(w[j][k] >0){
			w[i][t[i] + k] = max(w[i][t[i] + k],w[j][k] + a[i]);
			res = max(res,w[i][t[i] + k]);
		}
	}
	return res;
}

void process(){
	 for(int i = 1;i<=n;i++){
	 	w[i][t[i]] = a[i];
	 	ans = max(ans,a[i]);
	 	int limit = (i-D) >1 ? i-D : 1;
	 	int _t = T - t[i]; 
//		 cout<<" for i: "<<i<<" ans: "<<ans<<" limit: "<<limit<<"_ t "<<_t<<endl; 
	 
	 	for(int j = i-1; j >= limit; j-- ){
	 		ans = max(ans,compute(i,j,_t));
//	 		cout<<"Ans "<<ans<<endl;
//	 		cout<<"j = "<<j<<": "<<compute(i,j,_t)<<endl;
		 }
//		 for(int l = 1; l< T;l++) cout<<w[i][l]<<" ";
//		 cout<<endl;
	 }
}

int main(){
	input();
	process();
	cout<<ans;
}
