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

using namespace std;

int main(){
	string S,T;
	int i,K;
	cin >> K;
	cin >> S;
	if(S.size()<=K)cout << S << endl;
	else {
		myfor(i,K){
			cout<< S[i];
		}
		cout << "..." << endl;
	}
	return 0;
}