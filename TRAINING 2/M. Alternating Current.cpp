#include<bits/stdc++.h>

using namespace std;
stack<char> s;
string str;

int cnt;

int main(){
	getline(cin,str);
	int l = str.length();
	if(l <=1 || l%2 == 1) cout<<"No";
	else{
		for(int i = 0; i<l;i++){
			if(s.empty()) s.push(str[i]);
			else{
				if(s.top() != str[i]) s.push(str[i]);
				else s.pop();
			}
		}
		if(s.empty()) cout<<"Yes";
		else cout<<"No";
		
	}
}
