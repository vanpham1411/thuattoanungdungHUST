#include<bits/stdc++.h>

using namespace std;

int n;
const int N = 1e5+1;
//int a[N];
vector< pair <int, int> > v;
int res[N];
int t;

bool sortbysec(const pair<int,int> &a,const pair<int,int> &b){
	if(a.second <b.second) return true ;
	if(a.second == b.second && a.first < b.first ) return true;
	return false;
}

void input(){
	cin>>n;
	for(int i = 1;i<=n;i++){
		int b;
		scanf("%d",&b);
		v.push_back(make_pair(i,b));
	}
}


int main(){
	input();
	int t=0;
	sort(v.begin(),v.end(),sortbysec);
//	for(int i = 0;i <n;i++){
//		cout<<v[i].first<<" "<<v[i].second<<endl;
//	}
	
	for(int k = 0;k <n;k++){
		
		if(v[k].first > t ) res[v[k].first] = -1;
		else{
			res[v[k].first] = t - v[k].first-1;
		}
		t = t>v[k].first ? t: v[k].first;
		cout<<"res[ "<<v[k].first<<"]= "<<res[v[k].first]<<"t = "<<t<<endl;
	}
	for(int i =  1;i <=n;i++) printf("%d ",res[i]);
}
