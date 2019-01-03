#include<iostream>
#include <iomanip>
using namespace std;
int main(){
	int N,K,R[100];
	double rate=0.0;
	cin >> N >> K;
	for(int i=0;i<N;i++){
		cin >> R[i];
	}
	int tmp;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(R[i] < R[j]){
				tmp = R[j];
				R[j] = R[i];
				R[i] = tmp; 
			}
		}
	}
	for(int i=N-K;i<N;i++){

		rate = (rate + R[i])/2.0;
	}
	cout << fixed << setprecision(10)<< rate << endl;

		


	return 0;
	
}