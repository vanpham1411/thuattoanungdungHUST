#include <bits/stdc++.h>
using namespace std;

const int L = 1e4+1;
int n;
int a[L];
int mem[L];

void input(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
}

int lis(int i){
    if(mem[i] != -1){
        return mem[i];
    }
    int res = 1;
    for(int j=0; j<i; j++){
        if(a[j] < a[i]){
            res = max(res, 1+lis(j));
        }
    }
    mem[i] = res;
    return res;
}

int main(){
    input();
    memset(mem, -1, sizeof(mem));
    int max_S = 0;
    //max_S = 0;
    for(int i=0; i<n; i++){
        mem[i] = lis(i);
        max_S = max(max_S, mem[i]);
    }
    cout << max_S;
    return 0;
}