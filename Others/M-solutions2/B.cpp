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
	int A,B,C,K;
	cin >> A >> B >> C;
	cin >> K;
	int x=0,y;
	while(B <= A){
		B*=2;
		x++;
	}
	y = K - x;
	if(y >= 0){
		C *= pow(2,y);
	}else{
		cout << "No" << endl;
		return 0;
	}
	if(C > B && B > A)cout << "Yes" << endl;
	else cout << "No" << endl;

	return 0; 

}
