#include<bits/stdc++.h>

using namespace std;

int n;
int a[101];
vector<int> s1,s2,s3;

void input(){
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>a[i];	
	}
}

void process(){
	for(int i = 1; i<=n;i++){
		if(a[i] < 0) s1.push_back(a[i]);
		else if(a[i] > 0) s2.push_back(a[i]);
		else s3.push_back(a[i]);
	}
	sort(s1.begin(),s1.end());
	if(s2.size() == 0) {
		s2.push_back(s1[0]);
		s1.erase(s1.begin());
		s2.push_back(s1[0]);
		s1.erase(s1.begin());
	}
	if(s1.size() %2 == 0){
		s3.push_back(s1[0]);
		s1.erase(s1.begin());
	}
	sort(s2.begin(),s2.end());
	sort(s3.begin(),s3.end());
}

int main(){
	input();
	process();
	cout<<s1.size()<<" ";
	for(int i = 0;i<s1.size();i++ ){
		cout<<s1[i]<<" ";
	}
	cout<<endl;
	cout<<s2.size()<<" ";
	for(int i = 0;i<s2.size();i++ ){
		cout<<s2[i]<<" ";
	}
	cout<<endl;
	cout<<s3.size()<<" ";
	for(int i = 0;i<s3.size();i++ ){
		cout<<s3[i]<<" ";
	}
	return 0;
}
