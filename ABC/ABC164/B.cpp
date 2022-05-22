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
	int A,B,C,D;
	cin >> A >> B >> C >> D;
	if((C+B-1)/B <= (A+D-1)/D)cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
