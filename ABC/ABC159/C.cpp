#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <algorithm>
#include <string>
#include <iomanip>
#define myfor(i,N) for(i=0;i<N;i++)
#define myforFL(i,f,l) for(i=f;i<l;i++)

using namespace std;

int main(void){
	long L;
	float ans;
	cin >> L;
	ans = (L/3.)*(L/3.)*(L/3.);
	cout <<setprecision(10)<< ans << endl;
	return 0;
}