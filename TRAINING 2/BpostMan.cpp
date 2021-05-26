#include<bits/stdc++.h>

using namespace std;

int n, k;
//max heap
priority_queue<pair<long long , long long > > nepq;

priority_queue<pair<long long , long long> > popq;
long long  s=0;
void input(){
	
	cin>>n>>k;
	long long  x,m;
	long long p,q;
	
	for(int i = 0; i< n; i++){
		cin>>x>>m;
//		cout<<"x = "<<x<<", m = "<<m<<endl;
		if(x<0){
			x = -x;
			p = m/k;
			q = m%k;
			s+=x*p;
			if(q> 0 ) nepq.push(make_pair(x,q));
			cout<<"push "<<x<<q<<endl; 
		}
		else {
			p = m/k;
			
			q = m%k;
//			cout<<"x = "<<x<<", p = "<<p<<endl;
			s+=x*p;
			if(q> 0 ) popq.push(make_pair(x,q));
//			cout<<s<<endl;
		}
	}
	cout<<"s = "<<s<<endl;
	
}

void process(){
	int a = 0;
	int d;
	int maxd;
	while(!nepq.empty()){
//		cout<<"do negative PQ : "<<endl;
		
		a = a + nepq.top().second;
		d = nepq.top().first;	
		cout<<"POP "<<d<<" "<<a<<endl;
		nepq.pop();
		maxd = max(maxd, d);
		cout<<"MAXD = "<<maxd<<endl;
//		cout<<" a = "<<a<<" d = "<<d<<" dmax = "<<maxd<<endl;
		if(a >= k){
			
			s = s+ maxd;
			cout<<"S = "<<s<<endl;
			a = a%k;
//			cout<<"s = "<<s<<endl;
			if(a == 0 ) maxd = 0;
			else maxd = d;
//			cout<<"s = "<<s<<endl;
			cout<<"MAXD = "<<maxd<<endl;
		}
	}
	
	
	if(a >0) s = s+maxd;
	 a = 0;
//	cout<<"s = "<<s<<endl;
	
	while(!popq.empty()){
//		cout<<"do posetive PQ : "<<endl;
		
		a = a + popq.top().second;
		d = popq.top().first;	
		popq.pop();
		maxd = max(maxd, d);
//		cout<<" a = "<<a<<" d = "<<d<<" dmax = "<<maxd<<endl;
		if(a >= k){
//			cout<<"trong if: a = "<<a<<" d = "<<d<<" dmax = "<<maxd<<endl;
			s = s+ maxd;
			a = a%k;
//			cout<<"sau khi chia: a = "<<a<<" d = "<<d<<" dmax = "<<maxd<<endl;
			if(a == 0 ) maxd = 0;
			else maxd =d;
//			cout<<"s = "<<s<<" maxd = "<<maxd<<endl;
		}
	}
	
	
	if(a >0) s = s+maxd;
	 a = 0;
//	cout<<"s = "<<s<<endl;
	 s= s*2;
	
	cout<<s;
	
}

int main(){
	input();
	process();
	return 0;
}




	
