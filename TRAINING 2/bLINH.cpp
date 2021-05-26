#include <bits/stdc++.h>
using namespace std;
 

 
const int N = 5e3 + 5;
 
int n, m, k;
ll a[N];
ll f[N][N];
void solve(){
  string s;
  cin >> s;
  int n = Sz(s);
  s = ' ' + s;
  f[0][0] = 1;
  for(int i = 1; i <= n; i++){
    for(int j = 0; j <= n; j++){
      if(s[i] == '('){
        if(j > 0) f[i][j] = f[i - 1][j - 1];
      }
      if(s[i] == ')'){
        f[i][j] = f[i - 1][j + 1];
      }
      if(s[i] == '?'){
        f[i][j] = f[i - 1][j + 1];
        if(j > 0) f[i][j] += f[i - 1][j - 1];
      }
      f[i][j] %= MOD;
    }
 
  }
  cout << f[n][0] % MOD << "\n";
 
}
 
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout << fixed << setprecision(10);
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
  int query = 1;
  // cin >> query;
  int start = 1000 * clock() / CLOCKS_PER_SEC;
  while(query--) solve();
  cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC  - start << "ms\n";
}
