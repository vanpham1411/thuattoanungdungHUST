#include<bits/stdc++.h>

using namespace std;

string a;
int n;
stack<pair<int,char>> s;
vector<pair<int,int>> v;
int ans;
int cnt;
int pos = -1;
void input(){
	getline(cin,a);
}

void process(){
	n = a.length();
	s.push(make_pair(-1,'!'));
	for(int i = 0;i<n;i++){
		if(a[i] == '(' || a[i] == '[')
			s.push(make_pair(i,a[i]));
			
		else if(a[i] == ']'){
			if(!s.empty() && s.top().second == '[') s.pop();
			else s.push(make_pair(i,a[i]));
		}
		else if(a[i] == ')'){
			if(!s.empty() && s.top().second == '(') s.pop();
			else s.push(make_pair(i,a[i]));
		}
			
	}
	int k = n;
	while(! s.empty()){
		if(k - s.top().first >1)  v.push_back(make_pair(s.top().first+1,k-1));
		k = s.top().first;
		s.pop();
	}
	
	for(int i = 0;i < v.size();i++){
		cnt = 0;
		for(int j = v[i].first;j<= v[i].second;j++){
			if(a[j] == '[')  cnt++;
		}
		if(ans < cnt){
			ans = cnt;
			pos = i;
		}
	}
	if(pos == -1) {
		cout<<"0";
		if(v.size() >0){
			cout<<endl;
			for(int i = v[0].first;i<=v[0].second;i++){
				cout<<a[i];
			}
		}
		
	}
	else{
		cout<<ans<<endl;
		for(int i = v[pos].first;i<=v[pos].second;i++){
			cout<<a[i];
		}
	}
	
}

int main(){
	
	input();
	process();
}
