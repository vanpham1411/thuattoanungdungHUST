#include<bits\stdc++.h>

using namespace std;

int process(char c){
	switch(c){
		case 'a':
		case 'd':
		case 'g':
		case 'j':
		case 'm':
		case 'p':
		case 't':
		case 'w':
		case ' ':return 1;
		case 'b':
		case 'e':
		case 'h':
		case 'k':
		case 'n':
		case 'u':
		case 'x':
		case 'q':return 2;
		case 's':
		case 'z': return 4;
		case 'c':
		case 'f':
		case 'i':
		case 'l':
		case 'o':
		case 'r':
		case 'y':
		case 'v':return 3;
				
			
	}
}


int main(){
	int n;
	string s;
	cin>>n;
	getline(cin,s);
	for(int i = 0; i< n; i++){
		getline(cin,s);
		int cnt = 0;
		for(int j = 0; j< s.length();j++){
			cnt = cnt+ process(s[j]);
		}
		cout<<"Case #"<<i+1<<": "<<cnt<<endl;
	}
	
}
