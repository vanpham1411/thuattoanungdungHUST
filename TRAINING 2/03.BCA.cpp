#include<bits/stdc++.h>
using namespace std;

int load[11];//so luong mon hoc cua moi giao vien
int C[31];// so luong mon hoc
int load_max;//so luong mon hoc lon nhat co the day
int m, n;
int T[11][31];//giao vien i day mon j
int conflict[31][31];//2 mon khong the day boi cung mot giao vien
int ans = 50;

void input(){
	for(int i = 0; i <=30;i++) C[i] = 0;
	for(int i = 0; i <=10;i++){
		for(int j = 0; j <=30;j++){
			T[i][j] = 0;
		}
	}
	for(int i = 0; i <=10;i++) load[i] = 0;
	for(int i = 0; i <=30;i++){
		for(int j = 0; j <=30;j++){
			conflict[i][j] = 0;
		}
	}
	cin>>m>>n;
	
	for(int i = 1; i<=m; i++){
		cin>>T[i][0];
		for(int j = 1; j <=T[i][0];j++){
			cin>>T[i][j];
		}
	}
	int ki,row,col;
	cin>>ki;
	for(int i = 0; i <ki;i++){
		cin>>col>>row;
		conflict[col][row] = 1;
		conflict[row][col] = 1;
	}
}


//v;; teacher, k:course
bool check(int v, int k){
	//giao vien day 2 mon conflig khong
	for(int i = 1; i<= n;i++){
		if(conflict[k][i] == 1){
			if(C[i] == v) return false;
		}
	}
	//giao vien v duoc phep day mon k
	for(int i = 1; i<=T[v][0];i++){
		if(T[v][i] == k) return true;
	}
	return false;
}
void solution(){
	int max_load = *max_element(load,load+n+1);
	ans = ans <max_load ? ans : max_load;
	
}

void Try(int k){
	for(int v = 1; v<=m;v++){
		if(check(v,k)){
			C[k] = v;
			load[v]++;
			if(k ==n ) solution();
			else{	
			if(load[v] < ans) Try(k+1); 
			}
			C[k] = 0;
			load[v]--;
		}
	}
}

int main(){
	input();
	Try(1);
	if(ans == 50) cout<<-1;
	else cout<<ans;
	return 0;
}

//nhanh can: moi khi cho giao vien day mot mon, kiem tra so mon giao vien do day da vuot qua ans chua
// if load[v] <ans Try(k+1)

