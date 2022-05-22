#include <iostream>
#include <vector>
#include <numeric>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#define myfor(i,N) for(i=0;i<N;i++)
#define myforFL(i,f,l) for(i=f;i<l;i++)
#define myforInv(i,N) for(i=N;i>=0;i--)
#define myforFLInv(i,f,l) for(i=f;i>l;i--)
#define INF pow(10,14)
using namespace std;

int main(){
	int i,j,k,l;
	long N,M,X,C[12],A[12][12],B[12],cost,anscost = INF;
	cin >> N >> M >> X;
	myfor(i,N){
		cin >> C[i];
		myfor(j,M){
			cin >> A[i][j];
		} 
	}
	for(i=0;i<(1<<N);i++){
		myfor(l,M)B[l] = 0;
		cost = 0;
		for(j=0;j<N;j++){
			if(i & (1 << j)){
				myfor(k,M)B[k] += A[j][k];
				cost += C[j];
			}
		}
		myfor(l,M){
			if(B[l] < X)cost = INF;
		}
		anscost = min(anscost,cost);
	}
	if(anscost != INF)cout << anscost << endl;
	else cout << -1 << endl;

	return 0;
}