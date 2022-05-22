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
#define INF 100000000
using namespace std;
int D,G,p[10],c[10];

int main(){
	int i,N,left=0,right=0;
	vector <int> t;
	cin >> N;
	myfor(i,N){
		int tmp;
		cin >> tmp;
		t.push_back(tmp);
	}
	sort(t.begin(),t.end(),greater<int>());
	left = t[0];
	if(t.size()>1){
		right = t[1];
	}
	myforFL(i,2,N){
		if(left >= right){
			right += t[i]; 
		}else{
			left += t[i];
		}
	}
	cout << max(left,right) << endl;

	
	
	return 0;
}