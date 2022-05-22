#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <algorithm>
#include <string>
#define myfor(i,N) for(i=0;i<N;i++)
#define myforFL(i,f,l) for(i=f;i<l;i++)

using namespace std;

int main(void){
	int S,W;
	cin >> S >> W;
	if(S <= W) cout << "unsafe" << endl;
	else cout << "safe" << endl;
	return 0;
}
