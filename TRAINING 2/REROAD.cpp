#include<bits/stdc++.h>

using namespace std;
const int limit = 1e6 +1;
int n,q;
int t[limit];
int re;


void input(){
	re = 0;
	cin>>n;
	for(int i = 1; i <= n; i++){
		cin>>t[i];
	}
	t[0] = 0;
	t[n+1] = 0;
	int cmp = 0;
	for(int i = 0; i <= n-1; i++){
		if(t[i] != t[i+1]) {
			re++;
			cmp = t[i+1];
		}
	}
	cin>>q;
	
}

int process(int p){
	
	if(p == 1 && p == n) return 100;
	if(p ==1) return 0;
	if(p ==n) return -1;
	if(t[p] == t[p-1] && t[p]== t[p+1]) return 1;
	if(t[p] == t[p-1] || t[p] == t[p+1]) return 2;
	if(t[p] != t[p-1] && t[p] != t[p+1]) return 3;
	
}



// p: numerical order; c: type
int cals(int p, int c){
	int s ;
	s = process(p);
	int prev_t = t[p];
	
//	cout<<"s = "<<s<<endl;
	t[p] = c;
	 
	if(prev_t == c) return 0;
	if(s ==  100) return 0;
	if(s == 0 ) {
		if(prev_t == t[2]) return 1;
		if(t[1] == t[2] ) return -1;
		else return 0;
	}
	if(s == -1 ) {
		if(prev_t == t[n-1]) return 1;
		if(t[n-1] == t[n] ) return -1;
		else return 0;
	}
	if(s == 1) return 2;
	if(s == 2) {
		if(t[p] == t[p-1] || t[p] ==t[p+1]) return 0;
		else return 1;
	}
	if(s== 3){
		if(t[p] == t[p-1] && t[p] ==t[p+1]) return -2;
		if(t[p] == t[p-1] || t[p] ==t[p+1]) return -1;
		else return 0;
	}
}

int main(){
	input();
	int h,k;
	for(int i = 0; i < q; i++){
		cin>>h>>k;
	//	cout<<"cals: "<<cals(m,n)<<endl;
		int cal = cals(h,k);
		re = re+ cal;
		cout<<re<<endl;
		
//		for(int i = 1; i <= n; i++) cout<<t[i]<<" ";
//		cout<<endl;	
	}
}



