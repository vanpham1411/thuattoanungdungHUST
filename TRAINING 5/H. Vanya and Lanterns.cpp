#include<bits/stdc++.h>

using namespace std;

int n;
double l;
double a[1001];
double ans = 0;

int main(){
	cin>>n>>l;
	for(int i=1; i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	
	ans = max(a[1],l-a[n]);
	//cout<<ans<<endl;
	for(int i = 1; i<n;i++){
		double tmp = (a[i+1] - a[i])/2.0;
	//	cout<<tmp<<endl;
		ans = max(ans,tmp);
	}
	//cout<<ans<<endl;
	printf("%.10lf",ans);
}
