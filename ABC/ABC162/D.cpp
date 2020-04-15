#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <algorithm>
#include <string>
#define myfor(i,N) for(i=0;i<N;i++)
#define myforFL(i,f,l) for(i=f;i<l;i++)
using namespace std;
long solver1(int N, string S){
	long ans=0;
	string first,second,third;
	for (int i=0;i<N;i++){
		first = S[i];
		for(int j=i+1;j<N;j++){
			second = S[j];
			for(int k= j+1; k<N;k++){
				third = S[k];
				if(first != second && second != third && first != third && j-i != k-j){
					ans += 1;
				}
			}
		}
	}
	return ans;
}

long solver2(int N, string S){
	int R[4000],G[4000],B[4000],RNUM=0,GNUM=0,BNUM=0;
	long ans=0;
	for(int i=0;i<N;i++){
		if(S[i] == 'R'){
			R[RNUM] = i;
			RNUM++;
		}else if(S[i] == 'G'){
			G[GNUM] = i;
			GNUM++;
		}else{
			B[BNUM] = i;
			BNUM++;
		}
	}

	ans = RNUM*GNUM*BNUM;
	int a,b,c;
	long sub=0;
	for (int i=0;i<RNUM;i++){
		for(int j=0;j<GNUM;j++){
			for(int k=0; k<BNUM;k++){
				a = abs(R[i] - G[j]);
				b = abs(G[j] - B[k]);
				c = abs(R[i] - B[k]);
				if(a == b || b == c || c == a)sub++;
			}
		}
	}
	ans -= sub;
	return ans;
}

int main(void){
	long N,RNUM=0,GNUM=0,BNUM=0;
	string S;

	cin >> N;
	cin >> S;

	long ans=0;
	for(int i=0;i<N;i++){
		if(S[i] == 'R'){
			RNUM++;
		}else if(S[i] == 'G'){
			GNUM++;
		}else if(S[i] == 'B'){
			BNUM++;
		}
	}

	ans = RNUM*GNUM*BNUM;
	int i,j,k;
	myfor(i,N-2){
		myforFL(k,i+2,N){
			if((i+k)%2==0){
				j = (i+k)/2;
				if(S[i] != S[j] && S[j] != S[k] && S[k] != S[i])ans--;
			}
		}
	}
	
	cout << ans << endl;
	return 0;
}