#include<bits/stdc++.h>
using namespace std;

stack<char> s;
char c;
int n;
string str;

bool process(){
	getline(cin,str);
	int l = str.length();
//	cout<<"length : "<<l<<endl;
	for(int i = 0; i < l; i++){
//		cout<<i<<" :"<<str[i]<<" : ";
		
		if(str[i] == '(') s.push('(');
		else if(str[i] == '{') s.push('{');
		else if(str[i] == '[') s.push('[');
		else{
			if(s.empty()) return false;
			else{
				c = s.top();
//				cout<<c<<endl;
				if(str[i] == ')'&& c!= '(' ) return false; 
				if(str[i] == ']'&& c!= '[' ) return false;
				if(str[i] == '}'&& c!= '{' ) return false;
				s.pop();
				
			}
		}
		
	}
	return true;
}

int main(){
	cin>>n;
	getline(cin,str);
	for(int i = 0; i < n; i++){
		if(process()) cout<<"1 \n";
		else cout<<"0\n";
	}
}
