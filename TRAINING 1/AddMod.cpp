#include<bits/stdc++.h>

using namespace std;
long long a, b;
void input(){
	cin>>a>>b;
}
long long d = 1000000007;
void process(){
	long long c = a%d;
	c= c + b%d;
	c = c%d;
	cout<<c;
}

int main(){
	input();
	process();
}
