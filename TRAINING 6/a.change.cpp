#include<bits/stdc++.h>

using namespace std;

int a[6]={500,100,50,10,5,1};

int n;
int res;
int main(){
	cin>>n;
	n= 1000-n;
	for(int i = 0; i<6;i++) {
		res += n/a[i];
		n = n%a[i];
	}
	cout<< res;
}
