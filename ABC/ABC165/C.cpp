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
int N,M,Q,a[50],b[50],c[50],d[50],i,j,ansNow=0;

int dfs(vector <int> v,int N,int ans){
	if(v.size() == N+1){
		ansNow = 0;
		myfor(i,Q)if(v[b[i]]-v[a[i]]==c[i])ansNow+=d[i];
		ans = max(ans,ansNow);
		return ans;
	}
	v.push_back(v.back());
	
	while(v.back() <= M){
		ans = dfs(v,N,ans);
		v.back()++;
	}
	return ans;
}

int main(){
	
	cin >> N >> M >> Q;
	myfor(i,Q)cin >> a[i]>> b[i] >> c[i] >> d[i];
	int num[10];
	int ans = dfs(vector<int>(1,1),N,0);
	cout << ans << endl;
	
	
	return 0;
}