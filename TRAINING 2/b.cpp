#include<bits/stdc++.h>
using namespace std;

stack<char> s;

string str;
char a[1000];
int cnt = 0;
int dem = 0;
int mo,dong;
int m_mo,m_dong;
int l;

void TRY(int k){
	if(!s.empty()){
		if(str[k] == '(') {
			s.push('(');
			a[k] = str[k];
			if(k<l-1) TRY(k+1);
			s.pop();
		}
		else if(str[k] == ')' && s.top() == '('){
			s.pop();
			a[k] = str[k];
			if(k == l-1){
				if(s.top() == '0' ) {
					cnt++;
//					for(int j = 0; j<l;j++){
//						cout<<a[j];
//					}
//					cout<<endl;
				}
			}
			else if(k < l-1){
				 TRY(k+1);
			}
			s.push('(');
		}
		else if(str[k] == '?'){
			for(int i = 0; i<2;i++){
				if(i == 0){
					mo++;
					a[k] = '(';
					s.push('(');
					if(k<l-1 && mo <=m_mo) TRY(k+1);
					s.pop();
					mo--;
				}
				else{
					
					a[k] = ')';
					if(s.top() == '('){
						dong++;
						s.pop();
						if(k == l-1){
							if(s.top() == '0' ) {
								cnt++;
//								for(int j = 0; j<l;j++){
//									cout<<a[j];
//								}
//								cout<<endl;
							}
						}
						else if(k < l-1 && dong<=m_dong){
							TRY(k+1);
						}
						s.push('(');
						dong--;
					}
					
				}
			}
			
		}
		
	}  
	
}



int main(){
	int m = 0;
	int d = 0;
	getline(cin,str);
	l = str.length();
	for(int i = 0 ; i<l;i++){
		
		if(str[i] == '?') dem++;
		else if(str[i] == '(') m++;
		else d++;
		
		
	}
	d = d-m;
	m_mo = (dem+d)/2;
	m_dong = (dem-d)/2;
	s.push('0');
	TRY(0);
	cout<<cnt;
	
	
}
