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
	int H1,M1,H2,M2,K,awake_time;
	cin >> H1 >> M1 >> H2 >> M2 >> K;
	awake_time = (H2- H1)*60 + (M2 - M1);
	cout << awake_time - K << endl;

	return 0;
}
