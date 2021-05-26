#include<bits/stdc++.h>

using namespace std;

string str;
vector<pair<int,int>> s;
vector<pair<int,char>> v;
int n;
int ans = 0;
int cnt;
int pos = -1;


void input(){
	getline(cin,str);
	n = str.length();
	v.push_back(make_pair(-1,'!'));
	for(int i = 0;i<n;i++){
		v.push_back(make_pair(i,str[i]));
	}
	v.push_back(make_pair(n,'o'));
}

void process(){
	bool dowhile = true;
	
		for(int i = 1;i<v.size() -2;i++){
			if(v[i+1].second - v[i].second <=2 && v[i+1].second - v[i].second >=1 ) {
				v.erase(v.begin() +i);
				v.erase(v.begin() +i);
				dowhile = true;
				i = i-2;
			}
		}
		
	for(int i = 0; i<v.size() -1;i++){
		
		if(v[i+1].first - v[i].first >1) s.push_back(make_pair(v[i].first+1,v[i+1].first-1));
		
	}
	for(int i = 0;i < s.size();i++){
		cnt = 0;
		for(int j = s[i].first;j<= s[i].second;j++){
			if(str[j] == '[')  cnt++;
		}
		if(ans < cnt){
			ans = cnt;
			pos = i;
		}
	}
	if(pos == -1) {
		cout<<"0";
		if(s.size() >0){
			cout<<endl;
			for(int i = s[0].first;i<=s[0].second;i++){
				cout<<str[i];
			}
		}
		
	}
	else{
		cout<<ans<<endl;
		for(int i = s[pos].first;i<=s[pos].second;i++){
			cout<<str[i];
		}
	}
	
}

int main(){
	input();
	process();
	return 0;
}

