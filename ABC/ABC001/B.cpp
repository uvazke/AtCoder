#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;
int main(void){
	int m,ans;
	string VV;
	cin >> m;
	if(m < 1000){
		ans = m/100;
		VV = "0" + to_string(ans);
	}else if(m <= 5000){
		ans = m/100;
		VV = to_string(ans);
	}else if(m <= 30000){
		ans = m/1000 + 50;
		VV = to_string(ans);
	}else if(m <= 70000){
		ans = (m/1000-30)/5 + 80;
		VV = to_string(ans);
	}else{
		VV = "89";
	}
	
	cout << VV << endl;
	return 0;
}