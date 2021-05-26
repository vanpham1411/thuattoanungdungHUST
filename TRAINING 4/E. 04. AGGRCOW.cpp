#include<bits/stdc++.h>

using namespace std;

const int N = 100001;
int x[N];
int n,c;
int t;

bool check(long long limit)
{
	long long _prev = x[1];
	int C = 1;
	for(int i = 2; i<=n;i++){
		if(x[i] - _prev >= limit)
		{
			C++;
			_prev = x[i];
		}
		if(C>=c) return true;
	}
	//cout<<limit<<C<<endl;
	return C>=c;
}


long long find_bin(long long l, long long r){
	while(l<r){
		
		int mid = (l+r+1)/2;
		//cout<<l<<' '<<r<<" "<<mid<<endl;
		if(check(mid)) l = mid;
		else r = mid -1;	
	}
	return l;
}



int main(){
	cin>>t;
	while(t--){
		cin>>n>>c;
		//cout<<"c = "<<c<<endl;
		for(int i = 1; i<=n;i++ ){
			scanf("%d",&x[i]);
		}
		sort(x+1,x+n+1);
		cout<<find_bin(0,1000000000)<<endl;
		
	}
}

//loi o dong 24: vi duyet tu lon den be nen can kiem tra cnt>= c-1
//time limited:

