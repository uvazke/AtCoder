#include <iostream>

using namespace std;

int dp[2501],block[50][50],blockMax[2501],D[50][50];
void calcBlock(int N){
	block[N-1][N-1] = D[N-1][N-1];
	for(int i=N-2; i>=0;i--){
		block[i][N-1] = block[i+1][N-1] + D[i][N-1];
		block[N-1][i] = block[N-1][i+1] + D[N-1][i];
	}
	for(int i=N-2;i>=0;i--){
		for(int j=N-2;j>=0;j--){
			block[i][j] = block[i][j+1] + block[i+1][j] - block[i+1][j+1] + D[i][j]; 
		}
	}
	for(int i=1;i<=N*N;i++){
		blockMax[i] = 0;
	}
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			for(int k=0;k<N;k++){
				for(int l=0;l<N;l++){
					if(k+i == N && l+j == N){
						blockMax[i*j] = max(blockMax[i*j],block[k][l]);
					}else if(k+i == N){
						blockMax[i*j] = max(blockMax[i*j],block[k][l] - block[k][l+j]);
					}else if(l+j == N){
						blockMax[i*j] = max(blockMax[i*j],block[k][l] - block[k+i][l]);
					}else if(!(k+i > N || l+j > N)){
						blockMax[i*j] = max(blockMax[i*j],block[k][l] - block[k+i][l] - block[k][l+j] + block[k+i][l+j]);
					}
				}
			}
		}
	}
}

void calcDp(int N){
	dp[0] = 0;
	for(int i=1;i<=N*N;i++){
		dp[i] = max(dp[i-1],blockMax[i]);
	}
}

int main(){
	int N,Q,P[2500];
	cin >> N;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin >> D[i][j];
		} 
	} 
	cin >> Q;
	for(int i=0;i<Q;i++){
		cin >> P[i];
	} 
	calcBlock(N);
	calcDp(N);
	for(int i=0;i<Q;i++){
		cout << dp[P[i]] << endl;
	} 
	return 0;	
}