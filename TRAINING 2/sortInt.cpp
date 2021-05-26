#include<bits/stdc++.h>

using namespace std;
int N = 1e6+1;
int n;
int* a = new int[N];
int main(){
	
	cin>>n;
	
	for(int i = 0; i< n;i++){
		scanf("%d",&a[i]);
	}
	
	sort(a,a+n);
	for(int i = 0; i< n;i++){
		printf("%d ",a[i]);
	}
}


