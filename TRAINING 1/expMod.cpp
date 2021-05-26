#include<bits/stdc++.h>

using namespace std;

unsigned long long a,b , re;
unsigned long long m = 1000000007;

int main(){
	cin>>a>>b;
	re = 1;
	a = a% m;
	b = b% (m - 1);
	
	while(b>0){
		if(b%2>0){
			re = re * a % m;
			
		}
		
		b= b/2;
		a = a* a %m;
	}
	cout<<re;
	
}

