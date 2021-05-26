//#include<bits/stdc++.h>
//
//using namespace std;
//const int N_MAX= 1e6;
//int n;
//int a[N_MAX];
//
//void input(){
//	cin>>n;
//	for(int i = 0; i < n;i++){
//		cin>>a[i];
//	}
////	for(int i = 0; i < n;i++){
////		cout<<a[i]<<" ";
////	}
////	cout<<endl;
////	
//}
//
//void swap(int &m, int &n){
//	int tmp = a[n];
//	a[n] = a[m];
//	a[m] = tmp;
//}
//
//void solution(){
//	for(int i = 0; i <n; i++){
//		cout<<a[i]<<" ";
//	}
//}
//
//void insertionSort(int ){
//	for(int i = 1;i <n;i++){
//		cout<<"lan thu "<<i<<endl;
//		
//		cout<<endl;
//		for(int j = i; j > 0; j--){
//			if(a[j]<a[j - 1])  swap(a[j],a[j-1]);
//			else break;
//		}
//		for(int i = 0; i <n; i++){
//			cout<<a[i]<<" ";
//		}
//	}
//}
//
//
//int main(){
//	input();
////	insertionSort();
//	for(int i = 1;i <n;i++){
//			for(int j = i; j > 0; j--){
//			if(a[j]<a[j - 1])  {
//				int tmp = a[j];
//				a[j] = a[j-1];
//				a[j-1] = tmp;	
//			}
//		else break;
//		}
//	}	
//	solution();
//	return 0;
//}

#include<bits/stdc++.h>

using namespace std;
const int N_MAX= 1e6;
int n;
int a[N_MAX];

void input(){
	cin>>n;
	for(int i = 0; i < n;i++){
		cin>>a[i];
	}
}


void solution(){
	for(int i = 0; i <n; i++){
		cout<<a[i]<<" ";
	}
}


int main(){
	input();
	for(int i = 1;i <n;i++){
			for(int j = i; j > 0; j--){
			if(a[j]<a[j - 1])  {
				int tmp = a[j];
				a[j] = a[j-1];
				a[j-1] = tmp;	
			}
		else break;
		}
	}	
	solution();
	return 0;
}
