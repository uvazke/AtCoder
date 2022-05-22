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
string T;
long check(int flag){
	int i;
	long ans = 0;
	if(flag){for(i=0;i<T.length();i+=2)if(T[i] == '1')ans++;}
	else ans = (T.length()+1)/2;
	return ans;
}
int main(){
	int i,num;
	cin >> T;
	vector<int> inds;
	myfor(i,T.length()){
		if(T[i] == '0')inds.push_back(i);
	}
	long ans = 0;
	ans += check(1);
	num = T.length();
	for(i=0;i<num;i++){	
		if(!inds.empty()){
			T.erase(inds.back(),1);
			inds.pop_back();
			ans += check(1);
		}else{
			T.erase(T.length()-1,1);
			ans += check(0);
		}
	}
	cout << ans << endl;
	return 0;
}

