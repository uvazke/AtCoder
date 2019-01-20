#include <iostream>

using namespace std;

int main(){
	int T,N,M,A[100],B[100];
	cin >> T >> N;
	for(int i=0;i<N;i++){
		cin >> A[i];
	}
	cin >> M;
	for(int i=0;i<M;i++){
		cin >> B[i];
	}

	if(N<M){
		cout << "no" << endl;
		return 0;
	}
	int j=0;

	for(int i=0; i<N; i++){
		if(B[j] - A[i] < 0){
			cout << "no" << endl;
			return 0;
		}
		if(B[j] - A[i] <= T){
			j++;
		}
		if(j == M){
			cout << "yes" << endl;
			return 0;
		}
	}
	cout << "no" << endl;
	return 0;	
}