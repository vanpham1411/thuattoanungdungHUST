#include<bits/stdc++.h>

using namespace std;

const int N = 1e6+1;
int a[N];
int n;
long long s0[N],s1[N];
bool visited0[N],visited1[N];
long long ans = -1e9;

void input(){
	cin>>n;
	for(int i = 0; i<n;i++){
		scanf("%d",&a[i]);
	}
}

void compute(int k ){
	if(a[k]==0){
		if(k%2 == 0) {
			visited0[0] = true;
			s0[0] = a[0];
				
		}else{
			visited1[0] = true;
			s1[0] = a[0];
		}
	}
	
	if(a[k]%2 == 0){
		// even sum
		visited0[k] = true;
		s0[k] = a[k];
		if(visited0[k-1] == true) s0[k] = s0[k-1] > 0 ? s0[k-1]+a[k] : a[k];
		//odd sum
		if(visited1[k-1] == true) {
			visited1[k] = true;
			s1[k] = s1[k-1]+a[k];
		}
		
	}else{
		//k is odd
		//even sum
		if(visited1[k-1] == true){
			visited0[k] = true;
			s0[k] = s1[k-1]+a[k];
		}
		//odd sum
		visited1[k] = true;
		s1[k] = a[k];
		if(visited0[k-1] == true) s1[k] = s0[k-1] > 0 ? s0[k-1] + a[k] : a[k];
	}
}

int main(){
	input();
	for(int i =0; i<n; i++ ){
		compute(i);
		if(visited0[i] == true) ans = max(ans,s0[i]);
	}
//	for(int i =0; i<n; i++ ){
//		cout<<s0[i]<<" "<<s1[i]<<endl;
//		
//	}
	if(ans == -1e9) cout<<"NOT_FOUND";
	else cout<<ans;
}
