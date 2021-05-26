#include<bits/stdc++.h>

using namespace std;

int n;
int a[16];
int b[16];
int cnt;

bool cmp(int a,int b){
	return a>b;}

int main(){
	cin>>n;
	int dema = 0;
	int demb = 0;
	int dem3 = 0;
	for(int j = 0;j<n;j++){
		int var;
		cin>>var;
		if(var == 6) cnt++;
		else
		if(var == 3) dem3++;
		else if(var >3) {
			a[dema] = var;
			dema++;
		}
		else if(var <3){
			b[demb] = var;
			demb++;
		}
	}
	
	cnt = cnt+ dem3/2;
//	cout<<"cnt = "<<cnt<<endl;
	if(dem3%2 == 1){
		a[dema] = 3;
		dema++;
	}
//	cout<<"so phan tu:"<<dema<<demb<<endl;
	
	sort(a,a+dema,cmp);
	sort(b,b+demb);
//	cout<<"do sort"<<endl;
	int vt = 0;
	for(int i = 0;i<dema;i++){
		
		int s = a[i];
		//cout<<"i = "<<i<<" vt "<<vt<<" s = "<<s<<endl;
		
		if(vt >=demb){
			cnt+= dema-i;
			break;
		}else{
			while(vt <demb){
			//	cout<<"vt = "<<vt<<endl;
			if(s + b[vt] < 6) {
				if(vt == demb-1){
				
				cnt++;
			//		cout<<" vt == demb-1 cnt = "<<cnt<<endl;
				vt++;
				break;
			}
				
				s+= b[vt];
				vt++;
			}
			else{
				
				cnt++;
			//	cout<<"tang cnt"<<cnt<<endl;
				if(s+b[vt] == 6)  {
					vt++;
					//cout<<"tang vt";
				}
				break;
			}
		}
		}
		
		
	}
//	cout<<"after for cnt = "<<cnt<<endl;
	int tmp_s = 0;
	if(vt < demb){
		
		for(int i = vt; i<demb;i++){
			tmp_s += b[vt];
		}
	}
	cnt+= tmp_s/6;
	if(tmp_s%6 >0) cnt++;
	cout<<cnt;  
}
