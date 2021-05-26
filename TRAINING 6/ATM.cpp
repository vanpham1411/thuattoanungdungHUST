#include<bits/stdc++.h>

using namespace std;

int c;
long long w;
int n1;

long long pow10(int c){
	long long x = 1000;
	for(int i =1; i<=c;i++) x= x*10;
	return x;
}


int main(){
	cin>>n1;
	for(int s = 1; s<=n1;s++){
		long long n = 0;
		int cnt=1;
		cin>>w;
		cin>>c;
		if(w %1000 == 0){
			for(int i = c; i>=0;i--){
			 int res = 0;
			 long long a = w/pow10(i);
			 long long tmp = pow10(i);
			 w =(long long) w % tmp;
			 //cout<<"a = "<<a<<endl;
			 if(a >= 10) {
			 	if (a%10 == 1 || a%10 == 4) res++;
			 	n += a/10*2;
				 a = a %10;
				 
				 //cout<<"n = "<<n<<endl;
		    	}
			 if(a>0){
				 switch(a){
					case 1:
					case 2:
					case 3:
					case 5:
					case 7:
					case 8: res+=1;break;
					case 4: 
					case 6: res+=2;break;
					case 9: res+=3;break;
					
				}
				if(a == 9) n+=3;
				else if(a >5 || a == 4) n+=2;
				else n+=1;
				//cout<<"n = "<<n<<endl;
			}
			
			if (res >0) cnt = cnt*res;
			//cout<<c<<" "<<res<<" "<<cnt<<endl;
		}
		cout<<n<<" "<<cnt<<endl;
		}else cout<<"0\n";		
	}
}



// case 11 sai 


