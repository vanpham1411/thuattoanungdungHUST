#include<bits/stdc++.h>
using namespace std;

const int N = 1000005;
int a[N];
int w[N];
int cao[N]; //luu lai cac diem la dinh doi
int sau[N];// luu lai cac diem la day thung lung
vector< pair<int,int> > v_cao;
vector< pair<int,int> > v_sau;
int x1 = 0;
int x2 = 0;

vector<pair<int,int>> v[N];
int nbcao, nbsau;
int nb=0;
int n;

int doitrai(int x){
	for(int i = x-1; i>= 1;i--) if (a[i]>= a[i+1]) {
		
		return i+1;
	}
	return 1;
}
int doiphai(int x){
	for(int i = x+1; i<=n;i++) if (a[i]>= a[i-1]) {
	
	return i-1;
	
	}
	return n;
}
int thungtrai(int x){
	for(int i = x-1; i>= 1;i--) if (a[i]<=a[i+1]) {
	return i+1;
	}
	return 1;
}
int thungphai(int x){
	for(int i = x+1; i<=n;i++) if (a[i]<= a[i-1]) {
	return i-1;
	}
	return n;
}


int main(){
	
	//input
	cin>>n;
	for(int i = 1; i<=n;i++){
		scanf("%d",&a[i]);
	}
	a[0] = a[1];
	// tim doi:
	
	for(int i = 2; i<n;i++){
		if(a[i] > a[i-1]&& a[i] > a[i+1]){
			
			int x,y,z;
			y = doitrai(i);
			z = doiphai(i);
//			cout<<i<<y<<z<<endl;
			if(i != y && i != z){
				x = min(i-y,z-i);
				x1 = max(x1,x);
			}
			
		}
	}
	for(int i = 2; i<n;i++){
		if(a[i] < a[i-1]&& a[i] < a[i+1]){
			int x,y,z;
			y = thungtrai(i);
			z = thungphai(i);
//			cout<<i<<y<<z<<endl;
			if( i!= y && i!= z) {
				x = min(i-y,z-i);
				x2 = max(x2,x);
			}
			
		}
	}	
	cout<<x1<<" "<<x2;
	
	
}
