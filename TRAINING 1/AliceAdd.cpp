#include<iostream>

using namespace std;

unsigned long long A, B;
void input(){
	cin>>A>>B;
}

void process(){
	unsigned long long a = A/10;
	unsigned long long b = B/10;
	long long _a = A%10;
	long long _b = B%10;
	long long mod = (_a+_b )/10;
		if(a+b+mod>=1 ) cout<<a+b+mod;
	cout<<(_a+_b)%10;
}

int main(){
	
	int t;
	cin>>t;
	while(t--){
		input();
		process();
	}
	return 0;
}
