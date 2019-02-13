#include <iostream>
#include <iomanip>
using namespace std;
#define f(i, n) for(int i=0; i < n; i++)

int main() {
	int N,C[100],divisorNum[100];
	double p=0.0;
	cin >> N;
	f(i,N){
		cin >> C[i];
		divisorNum[i] = 0;
	}
	f(i,N)f(j,N)if (i!= j && C[i]%C[j] ==0)divisorNum[i]++;
	f(i,N){
		if(divisorNum[i]%2==0)p += double(divisorNum[i]+2)/double(2*divisorNum[i]+2);	
		else p += 0.5;
	}
	cout << fixed << setprecision(10)<< p << endl; 
	return 0;
}