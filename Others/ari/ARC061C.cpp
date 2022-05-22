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


float distance(long x1,long y1,long x2,long y2){
	return pow((y2 - y1)*(y2 - y1) + (x2 - x1)*(x2 - x1),1./2.);
}

int main(){
	string S;
	long ans=0,i,j;
	cin >> S;
	long separation = S.size()-1;
	myfor(i,S.size()){
		myfor(j,separation-i){
			ans += (S[i] - '0')*pow(10,j)*pow(2,separation-j-1);
		}
		ans += (S[i] - '0')*pow(10,j)*pow(2,separation-j);
	}
	cout << ans << endl;
	return 0;
}


//1234 separation = 3
//1|2|3|4
//1 -> *1: 2^2 *10: 2^1 *100: 1 *1000: 1
//2 -> *1: 2^2 *10: 2^1 *100: 2
//3 -> *1: 2^2 *10: 2^2
//4 -> *1: 2^3

//12345
//1|2|3|4|5
//1 -> *1: 2^3 *10: 2^2 *100: 2^1 *1000: 1, *10000: 1
//2 -> *1: 2^3 *10: 2^2 *100: 2^1 *1000: 2
//3 -> *1: 2^3 *10: 2^2 *100: 2^2
//4 -> *1: 2^3 *10: 2^3
//5 -> *1: 2^4