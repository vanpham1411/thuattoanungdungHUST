#include<bits/stdc++.h>

using namespace std;
const int N = 1000;
int n;
int s[N];
int ans=0;
int cnt = 0;
struct block{
	int x;
	int y;
	int z;
}Block[1000];

bool cmp(block u,block v){
	if(u.x != v.x) return u.x > v.x;
	if(u.y != v.y) return u.y > v.y;
	return u.z > v.z;
}

bool better(block v,block u){
	return (v.x >u.x) && (v.y > u.y);
}

void input(){
	int a[3];
	//cout<<"cnt = "<<cnt<<endl;
	for(int i = 0; i<n;i++){
		cin>>a[0]>>a[1]>>a[2];
		sort(a,a+3);
		do {
			Block[cnt].x = a[0];
			Block[cnt].y = a[1];
			Block[cnt].z = a[2];
			cnt++;
		}while(next_permutation(a,a+3));
	}
	sort(Block,Block + cnt,cmp);
	//cout<<"cnt after input = "<<cnt<<endl;
	
}

int tower(int t){
	
		s[t] = Block[t].z;
			//cout<<"do if\n";
		for(int i = t-1; i>=0;i--){
			if(better(Block[i], Block[t])) {
				s[t] = s[t] >(s[i] + Block[t].z) ? s[t] : (s[i] + Block[t].z);
				//cout<<s[i] + Block[t].z<<endl;
			}
		}		
	return s[t];
	
}

void checkInput(){
	for(int i = 0;i<N;i++ ){
		cout<<Block[i].x<<" "<<Block[i].y<<" "<<Block[i].z<<endl;
	}
}

int main(){
	cin>>n;
	int nb = 1;
	while (n!=0){
		//checkInput();
		
		cnt = 0;
		input();
		ans = Block[0].z;
		s[0] = Block[0].z;
		//checkInput();
		for(int i = 1; i<cnt;i++){
			if(tower(i) > ans) ans = tower(i);
		}
//		for(int i = 0; i<cnt;i++){
//			cout<<s[i]<<endl;
//		}
		cout<<"Case "<<nb<<": maximum height = "<<ans<<endl;
		nb++;
		cin>>n;
	}
	
}


// N = 1000 moi dung
