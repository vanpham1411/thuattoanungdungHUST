#include<bits/stdc++.h>
using namespace std;
int t,n;

const int N = 1001;

int x[N];
int y[N];

int cmp(int a,int b){
	return a>b;
}

int main(){
	cin>>t;
	int dem = 1;
	while(dem<= t){
		long long ans = 0;
		cin>>n;
		for(int i = 0; i<n;i++){
			scanf("%d",&x[i]);
		}
		for(int i = 0; i<n;i++){
			scanf("%d",&y[i]);
		}
		sort(x,x+n);
		sort(y,y+n,cmp);
		
		for(int i = 0;i<n;i++){
			ans += (long long)x[i]*y[i];
			//cout<<x[i]<<" "<<y[i]<<" "<<ans<<endl;
		}
		cout<<"Case #"<<dem<<": "<<ans<<endl;
		dem++;
	}
	
}
