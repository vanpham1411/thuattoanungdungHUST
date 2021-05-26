#include<bits/stdc++.h>

using namespace std;

int n;
string p;
long long res = 0;
typedef struct{
	string L;
	string R;
	
} String;

String f[101];
long long F[101];


long long Count(string p,string s){
	int index = 0;
	long long app = 0;
	while (true){
		index = s.find(p,index);
		if(index == -1) break;
		app++;
		index++;
	}return app;
	
	
}

int main(){
	int test = 0;
	while(cin>>n>>p){
		test++;
		for(int i = 1; i<= n;i++){
			f[i].L = f[i].R = "";
			F[i] = 0;
		}
		f[0].L = "0";
		f[0].R = "0";
		f[1].L = "1";
		f[1].R = "1";
		
		int N = 1;
		string f0 = "0";
		string f1= "1";
		while (f0.length() <= p.length()){
			N++;
			string tcmp = f1+f0;
			f0 = f1;
			f1 = tcmp;
			if(N== n){
				res+= Count(p,f1);
				break;
			}
		}
		if(N == n){
			continue;
		}
		f[N-1].L = f0.substr(0,p.length()-1);
		f[N-1].R = f0.substr(f0.length() -(p.length()-1), p.length()-1);
		f[N].L = f1.substr(0,p.length()-1);	
		f[N].R = f1.substr(f1.length() -(p.length()-1), p.length()-1);
		F[N-1] = Count(p,f0);
		F[N] = Count(p,f1);
		
		for(int i = N+1;i<=n;i++){
			F[i] = F[i-1]+F[i-2];
			long long tcmp = Count(p,f[i-1].R+f[i-2].L);
			F[i]+= tcmp;
			
			f[i].L = f[i-1].L;
			f[i].R = f[i-2].R;
		}
		cout<<"Case "<<test<<": "<<F[n]<<endl;
	}
}
