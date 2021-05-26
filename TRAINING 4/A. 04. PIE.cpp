#include<bits/stdc++.h>
 
using namespace std;

const double pai = acos(-1);
const int N = 10001;
int n,f;
double a[N];

double _max;
double _min = 0.0;
int nb;

void input(){
	
	cin>>n>>f;
	int s = 0;
	for(int i = 0; i <n;i++){
		scanf("%lf",&a[i]);
		a[i] = a[i]*a[i];
		_max = max(_max,a[i]);
	}

}
int main(){
	cin>>nb;
	while (nb > 0){
		input();
		f++;
		
		double mid;
		_min = 0;
		while (_min + 1e-7 <_max){
			mid = (_min+_max)/2;
			int cnt = 0;
			for(int i = 0; i<n;i++){
				cnt +=(int) floor(a[i]/mid); 
			}
			if(cnt <f){
				_max = mid;
			}else{
				_min = mid;
			}
//			cout<<min<<" "<<max<<endl;
		}
		_min =(double) _min*pai;
		printf("%.6lf\n",_min);
		nb--;
	}
}

// max = gia tri lon nhat cua mang a[]



