#include<bits/stdc++.h>

using namespace std;

int main(){
	int N;
	cin>>N;
	long long a[INT_MAX];
	for(int i = 1; i <=N;i ++){
		cin>>a[i];
	}
	long long T = a[0];
    long long max = T;
    for(int i = 1; i <=N; i++){
        if(T > 0) T = T + a[i];
        else T = a[i];
        max = max < T ? T : max;
    }
    cout<<max;
}
