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

int getMinimumNumForTheIndex(int score, int num, int index){
	score -= c[index]+100*(index+1);
	int numOfReducedProblem = 0;
	while(score >= G && numOfReducedProblem < p[index]){
		score -= 100*(index+1);
		numOfReducedProblem++; 
	}
	if(numOfReducedProblem == p[index])return INF;
	return num - numOfReducedProblem;
}

int getMinimumNumForTheIndexList(int score, int num, vector<int> usedIndexList){
	int i,usedIndex,ans=INF;
	myfor(i,usedIndexList.size()){
		usedIndex = usedIndexList[i];
		ans = min(ans, getMinimumNumForTheIndex(score,num,usedIndex));
	}
	return ans;
}

int dfs(int score,int num,int index, vector<int> usedIndexList){
	int i,ans=INF;
	int newScore = score + 100*(index+1)*p[index] + c[index];
	if(index + 1 < D)ans = dfs(score,num,index+1, usedIndexList);
	usedIndexList.push_back(index);
	if(index + 1 < D) ans = min(ans,dfs(newScore,num+p[index],index+1, usedIndexList));
	if(newScore>=G){
		return min(ans,getMinimumNumForTheIndexList(newScore,num+p[index],usedIndexList));
	}
	return ans;
}

int main(){
	int i;
	cin >> D >> G;
	myfor(i,D)cin >> p[i] >> c[i];
	int point,points[10];
	int ans;
	vector<int> v;
	ans = dfs(0,0,0,v);
	cout << ans << endl;
	return 0;
}