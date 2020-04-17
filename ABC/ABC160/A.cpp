#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <algorithm>
#include<string>
#define myfor(i,N) for(i=0;i<N;i++)
#define myforFL(i,f,l) for(i=f;i<l;i++)

using namespace std;

int main(void){
	string S;
	cin >> S;

	if(S[2] == S[3] && S[4] == S[5])cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}