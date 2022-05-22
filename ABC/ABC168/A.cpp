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
	string S;
	cin >> S;
	int i = S.size()-1; 
	if (S[i] == '2' || S[i] == '4' || S[i] == '5' || S[i] == '7' || S[i] == '9')cout << "hon" << endl;
	else if (S[i] == '3') cout << "bon" << endl;
	else cout << "pon" << endl;
	return 0;
}
