#include<bits/stdc++.h>

using namespace std;

int n, k1,k2;
int check = 0;
int cnt = 0;

// ngay thu i co gia tri j, co l ngay lam viec lien tiep

//0: ngay lam
//1: ngay nghi
void TRY(int i, int j, int l){
	if(i == n) {
		if(l < k1 && j == 0) return;
		cnt++;
	}
	else{
		if(l>=k1) TRY(i+1,1,0);
		if(l<k2) TRY(i+1,0,l+1);
	}
	
}

int main(){
	cin>>n>>k1>>k2;
	TRY(1,0,1);
	TRY(1,1,0);
	cout<<cnt;
}
