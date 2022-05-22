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
	long long X,money=100,year=0;
	int i,j;
	cin >> X;
	while(money < X){
		money *= 1.01;
		year++;
	}
	cout << year << endl;
	return 0;
}