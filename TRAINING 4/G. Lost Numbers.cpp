#include<bits/stdc++.h>

using namespace std;

int a[7];
int init[]={4,8,15,16,23,42};
bool visit[6];
int x13,x12,x45,x46;

int check(int m,int y){
	for(int i = 0;i<6;i++){
		if(m == init[i] && y!=i) return i;
	}
	return 6;
}

int process(int s1,int s2 ){
	for(int i = 0; i<6;i++){
		if(s1%init[i] == 0 && s2%init[i] == 0 ) {
			int x = s1/init[i];
			int y = s2/init[i];
			if((check(x,i)<6) && (check(y,i)<6)) {
				
				return i;
			}
			
		}
	}
}

int main(){
	printf("? 1 2\n");
	cin>>x12;
	cout<<"? 1 3\n";
	cin>>x13;
	cout<<"? 4 5\n";
	cin>>x45;
	cout<<"? 4 6\n";
	cin>>x46;
	
	a[1]= init[process(x12,x13)];
	a[2] = x12/a[1];
	a[3] = x13/a[1];
	
	a[4]= init[process(x45,x46)];
	a[5] = x45/a[4];
	a[6] = x46/a[4];	
	
	fflush(stdout);
	cout<<"! "<<a[1]<<" "<<a[2]<<" "<<a[3]<<" "<<a[4]<<" "<<a[5]<<" "<<a[6]<<endl;
	
}
