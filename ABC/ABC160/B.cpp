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
	int X,ans;
	cin >> X;
	ans = 1000*(X/500) +5*((X%500)/5);
	cout << ans <<endl; 
	return 0;
}