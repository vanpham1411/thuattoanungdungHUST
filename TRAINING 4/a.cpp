#include<bits/stdc++.h>
using namespace std;
int t,n;

const int N = 1001;

int x[N];
int y[N];
long long ans = 0;
bool visited[N];
long long res= 1e10;
int cmp(int a,int b){
	return a>b;
}

void input(){
	cin>>n;
		for(int i = 0; i<n;i++){
			scanf("%d",&x[i]);
		}
		for(int i = 0; i<n;i++){
			scanf("%d",&y[i]);
		}
		sort(x,x+n);
		sort(y,y+n,cmp);
}

bool check(int v,int k){
	return !visited[v];
}

void TRY(int k){
	for(int v = 0; v<n;v++){
		if(check(v,k)){
			
			ans += x[k]*y[v];
			//cout<<endl<<x[k]<<" "<<y[v]<<" "<<ans<<endl;
			visited[v] = true;
			if(k == n-1) {
				res = min(ans,res);
				//cout<<"ans = "<<ans<<endl;
			}
			else if(ans<res) TRY(k+1);
			ans -= x[k]*y[v];
			visited[v] == false;
		}
	}
}

int main(){
	cin>>t;
	int dem = 1;
	while(dem<= t){
		for(int i = 0; i<n;i++){
			visited[i] = false;
		}
		ans = 0;
		res = 1e9;
		input();
		
		
		TRY(0);
		cout<<"Case #"<<dem<<": "<<res<<endl;
		dem++;
	}
	
}
