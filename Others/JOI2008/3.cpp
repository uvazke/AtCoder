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
#define MAXDIF 126 //pow(pow(10.,9.),1./5.)*2
using namespace std;

long N,M;
vector <long> P;

long dfs(vector<long> v,long ind){
	long i;
	long ans=accumulate(v.begin(), v.end(), 0);
	if(ans > M)return 0;
	
	myforFL(i,ind,N){
		vector<long> v2 = v;
		v2.push_back(P[i]);
		if(v2.size() <= 4)ans = max(dfs(v2,i),ans);
	}

	return ans;
}

int main(){
	long i,p;
	cin >> N >> M;
	myfor(i,N){
		cin >> p;
		P.push_back(p);
	}
	sort(P.begin(),P.end(),greater<long>());
	vector<long> v;
	long ans = dfs(v,0);

	cout << ans << endl;
	return 0;
}
