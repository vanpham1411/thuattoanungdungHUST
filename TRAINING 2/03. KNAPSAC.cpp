#include<bits/stdc++.h>

using namespace std;

int n, b;
int ans = 0;
int cura, curc;
vector<pair<int, int>> vt;
int val;
bool visited[50];
int c_max;

bool compare(pair<int, int> a, pair<int, int> b){
	if(a.second *100/a.first > b.second*100/b.first) return true;
	if(a.second *100/a.first < b.second*100/b.first) return  false;
	if(a.first >= b.first ) return true;
	else return false;
}

void input(){
	cura = 0;
	curc = 0;
	//a:khoi luong, c: gia tri su dung
	int a, c;
	cin>>n>>b;
	for(int i = 0; i < n; i++){
		cin>>a>>c;
		vt.push_back(make_pair(a,c));
	}
	sort(vt.begin(), vt.end(), compare);
	for(int i = 0; i < n; i++){
		visited[i] = false;
	}
	c_max = vt[0].second/vt[0].first;
}
//void solution(){
//	if(ans<curc) ans = curc;
//}
bool check(int v,int k){
	if(visited[v]) return false;
	if(cura+ vt[v].first <= b) return true;
	return false;
}
void Try(int k){
	for(int v = 0; v <n; v++){
		if(((b - cura)*c_max +curc )< ans) break;	
		if(check(v,k)){
			
		//	cout<<"try "<<v<<endl;
			visited[v] = true;
			cura =cura+ vt[v].first;
		//	cout<<"curc = "<<curc<<endl;
			curc = curc+ vt[v].second;
		//	cout<<vt[v].first<<" "<<vt[v].second<<endl;
		//	cout<<"curc = "<<curc<<endl;
			if(ans<curc) ans = curc;
		//	cout<<"ans = "<<ans<<endl;
			Try(k+1);
			cura = cura - vt[v].first;
			curc = curc- vt[v].second;
			visited[v] = false;
			
		}
	
	}
}
void checkInput(){
	cout<<"check input\n";
	for(int i = 0; i< n; i++){
		cout<<vt[i].first<<" "<<vt[i].second<<endl;
	}
	cout<<endl;
}

void process(){
	for(int i = 0; i < n; i++){
		if(cura+ vt[i].first <= b){
			cura= cura + vt[i].first;
			curc = curc+ vt[i].second;
		}
	}
	//cout<<curc;
}

int main(){
	input();
//	checkInput();
//	process();
	Try(0);
	cout<<ans;
}
