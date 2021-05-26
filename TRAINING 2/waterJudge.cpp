#include<bits/stdc++.h>

using namespace std;
typedef pair<int, int> pairs;
//save the state
queue<pairs> q;
//check the state
set<pairs> s;
int a,b,c;
int cnt = 0;

bool check_re(pairs state){
	if(state.first == c || state.second == c) return true;
	else return false;
}

bool check_ch(pairs stt){
	return s.find(stt) == s.end();	
}

int process(){
	
	while(!q.empty()){

		int luong = q.size();
		for(int o = 0; o < luong; o++){
			pairs x = q.front();
			q.pop();
			//cout << "\nPOP: (" << x.first << ", "<< x.second << ")"<< " "<<endl;
			
			if(check_ch(x)){
				s.insert(make_pair(x.first,x.second));
				//Create new state
				pairs p_state[6];
				p_state[0] = make_pair(0,x.second);
				p_state[1]= make_pair(x.first,0);
				p_state[2] = make_pair(a,x.second);
				p_state[3] = make_pair(x.first,b);
				int pst1, pst2,pstt;
				pstt = x.first + x.second;
				pst1 = pstt <=b ? pstt:b;
				pst2 = pstt <= b ? 0: pstt-b;
				p_state[4] = make_pair(pst2,pst1);
				pst1 = pstt <=a ? pstt:a;
				pst2 = pstt <= a ? 0: pstt-a;
				p_state[5] = make_pair(pst1,pst2);	
				//check new state	
				for(int i = 0; i <6; i++){	
					//cout << "CHECK: (" << p_state[i].first << ", "<< p_state[i].second << ")"<< " \n";
					if(check_re(p_state[i])) {
						cnt++;
						return 1;
					}
					if(check_ch(p_state[i])){
						//cout<<"\nPUSH:"<< "(" << p_state[i].first << ", "<< p_state[i].second << ")"<< "\n ";
						q.push(p_state[i]);
					}
				}
			
			}
		}
		cnt++;
	}
	return -1;
}

int main(){
	cin>>a>>b>>c;
	q.push(make_pair(0,0));
	//s.insert(make_pair(0,0));
	if(process() == 1) cout<<cnt;
	else cout<<"-1";

}

//	pairs x= make_pair(2,3);
//	s.insert(x);
//	s.insert(make_pair(2,1));
//	for(auto const &x : s){
//		cout << "(" << x.first << ", "<< x.second << ")"<< " "; 
//	}
//	q.push(x);
//	pairs t = q.front();
//	cout<<t.first<<" "<<t.second;

