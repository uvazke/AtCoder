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

using namespace std;

int main(){
	int i,M,N;
	cin >> N;
	cin >> M;

	myfor(i,M){
		cout << (N/2-M)+i+1 <<" " <<(N/2+M)-i << endl;
	}
	return 0;
}