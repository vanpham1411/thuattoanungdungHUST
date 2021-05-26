#include<bits/stdc++.h>

using namespace std;

int n;
int a[7];
bool visited[10];
int cnt = 0;
// C, T, D, L, G, U
// CTDLGT + TTUD = N
bool check(int k, int v){
	if(k == 1&& v==0) return false;
	if(k == 2 && v==0) return false;
	if(visited[v])  return false;
	return true;
}

void TRY(int k){
	for(int v = 0; v<=9;v++){
		if(check(k,v)){
			a[k] = v;
			visited[v] = true;
			if(k == 6){
				int sh1 = a[1]* 100000 +  a[2]* 10000 + a[3]*1000 +a[4]*100+a[5]*10+a[2];
				int sh2 = a[2]*1000 + a[2]*100+a[6]*10+a[3];
				if(sh1 + sh2 == n) cnt++;
			}
			else if(k < 6) TRY(k+1);
			a[k] = 0;
			visited[v] = false;
		}
	}
}

int main(){
	
	cin>>n;
	TRY(1);
	cout<<cnt;
	
}
