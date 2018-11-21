#include<iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main (void)
{
	double dp[11][1024];
	int K,R[1024];

	cin >> K;
	for(int i=0;i<int(pow(2,K));i++){
		cin >> R[i];
	}

	for(int j=0;j<int(pow(2,K));j++)dp[0][j] = 1.0;

	double sum=0.0,p=0.0;
	for(int i=1;i<=K;i++){
		for(int j=0;j<int(pow(2,K));j++){
			if(j%int(pow(2,i)) >= int(pow(2,i-1))){
				for(int k=0;k<int(pow(2,i-1));k++){
					p = 1/(1+pow(10,(R[int(pow(2,i))*(j/int(pow(2,i)))+k]-R[j])/400.0));
					sum+=dp[i-1][int(pow(2,i))*(j/int(pow(2,i)))+k]*p;
				}
				dp[i][j] = dp[i-1][j]*sum;
			}else{
				for(int k=int(pow(2,i-1));k<int(pow(2,i));k++){
					p = 1/(1+pow(10,(R[int(pow(2,i))*(j/int(pow(2,i)))+k]-R[j])/400.0));
					sum+=dp[i-1][int(pow(2,i))*(j/int(pow(2,i)))+k]*p;
				}
				dp[i][j] = dp[i-1][j]*sum;
			}
			sum=0.0;
		}
	}
	cout << fixed;
	for(int i=0;i<int(pow(2,K));i++)cout << setprecision(9) << dp[K][i] << endl;
}