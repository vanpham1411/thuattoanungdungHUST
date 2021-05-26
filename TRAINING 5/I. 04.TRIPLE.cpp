#include<bits/stdc++.h>

using namespace std;

int a[5001];

int n,k,ans;

int findj(int i,int k,int x){
	int cnt = 0;
	while(i<= k){
		int mid = (i+k)/2;
		if(a[mid] == x){
			cnt = 1;
			int l = mid-1;
			int r = mid+1;
			while(l>=i){
				if(a[l] == a[mid]){
					cnt++;
					l--;
				}
				else break;
			}
			while(r<=k){
				if(a[r] == a[mid]){
					cnt++;
					r++;
				}
				else break;
			}
			return cnt;
		}
		else {
			if(a[mid] > x) k = mid-1;
			else i = mid+1;
		}
	}
	return 0;
}



input(){
	cin>>n>>k;
	for(int i = 0; i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
//	for(int i = 0; i<n;i++){
//		cout<<a[i]<<" ";
//	}
//	cout<<endl;
}

int main(){
	input();
	for(int i = 0;i<n-2;i++){
		int _s = k-a[i];
		for(int j = n-1; j>1;j--){
			if (_s > a[j]){
//				if(find(a+i+1,a+j,_s-a[j]) != (a+j)) ans++;
				ans+= findj(i+1,j-1,_s - a[j]);
				
			}
		}
	}
	cout<<ans;
}
