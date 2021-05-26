#include<bits/stdc++.h> 
using namespace std;

const long long limit = 1e6+9;
const long long oo = 1e17;
int n;
long long l[limit];

long long left1[limit];
long long right1[limit];


void input(){
	cin>>n;
	for(int i = 1; i<= n;i++ ) cin>>l[i];
} 


//O(n)
void process3(){
	left1[1] = 1;
	right1[n] = n;
	for(int i = 2; i<= n; i++){
		if(l[i] <= l[i -1]) {
			left1[i] = left1[i -1];
			for(int t = left1[i]-1; t >0 ;){
				if(l[i] <= l[t]){
					left1[i] = left1[t];
					t = left1[i]-1;
				}else  break;
			}
		}
		else left1[i] = i; 
	}
	
	for(int j = n-1; j>= 1; j--){
		if(l[j] <= l[j +1]) {
			right1[j] = right1[j+1];
			int i = j;
			right1[i] = right1[i +1];
			for(int t = right1[i]+1; t <n+1 ;){
				if(l[i] <= l[t]){
					right1[i] = right1[t];
					t = right1[i]+1;
				}else  break;
			}
		}
		else right1[j] = j; 
	}
	long long s = 0;
	long long res = 0;
	for(int i = 1; i<= n; i++){
		s = l[i] * (right1[i] - left1[i] + 1);
		res = max(s, res);
	}
	cout<<res<<endl;
}

int main(){
	while(true){
		input();
		if(n == 0 ) break;
	process3();
	}
}


