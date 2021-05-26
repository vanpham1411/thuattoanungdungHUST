#include<bits/stdc++.h>

using namespace std;

int n;
const int N = 1e5+1;
int a[N];
int res[N];
int t;

void input(){
	cin>>n;
	for(int i = 1;i<=n;i++){
		scanf("%d",&a[i]);
	}
}

void TRY(int k){
	if(k == n) res[k] = -1;
	else{
		t = k;
		int i = k;
		for(int i = k;i<=n;i++){
			if(res[i] == -1 && a[i] > a[k]){
				break;
			}
			if(a[k]>a[i]) {
				t = i;
				if(res[i]>0) i+=res[i];
			}
			
		}
		
		res[k] = t - k - 1;
	}
}
int main(){
	input();
	for(int i = n;i >=1;i--){
		TRY(i);
	}
	for(int i =  1;i <=n;i++) cout<<res[i]<<" ";
}
