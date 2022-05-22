#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <algorithm>
#include <string>
#include <unordered_map>
#define myfor(i,N) for(i=0;i<N;i++)
#define myforFL(i,f,l) for(i=f;i<l;i++)

using namespace std;

int main(void){
	int N,i,ans;
	string S[200000];
	unordered_map<string, int> mp;
	cin >> N;
	myfor(i,N){
		cin >> S[i];
		mp[S[i]] = 1;
	}
	ans = mp.size();
	cout << ans << endl;
	
	return 0;
}
