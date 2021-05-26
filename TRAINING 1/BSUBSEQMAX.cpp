#include<bits/stdc++.h>
using namespace std;


int main(){
	int n;
	cin>>n;
	int a[n], re[n];
	int s = 0;
	for(int i = 0; i < n;i ++){
		cin>>a[i];
	}
	for(int i = 0; i< n; i++){
		if(a[i] > 0 ) re[i] = re[i - 1] + a[i];
		else re[i]= 0;
	}
	
	cout<<*max_element(re, re+n);
//	for(int i = 0; i < n;i ++){
//		cout<<re[i];
//	}
}
