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
int dx[]={1,-1,0,0,1,-1,1,-1},dy[]={0,0,1,-1,1,-1,-1,1};
int w,h;
vector<vector<int> >c(50, vector<int>(50));
vector<vector<bool> >done(50, vector<bool>(50,false));

int dfs(int x, int y){
	int i;
	if(c[x][y] == 0)return 0;
	
	myfor(i,8){
		if(x+dx[i]>=0&&x+dx[i]<w && y+dy[i]>= 0 && y+dy[i] < h )if(!done[x+dx[i]][y+dy[i]]&& c[x+dx[i]][y+dy[i]] == 1){
			done[x+dx[i]][y+dy[i]] = true;
			dfs(x+dx[i],y+dy[i]);
		}
	}
	done[x][y] = true;
	return 1;
}
int mainloop(int win, int hin){
	int i,j,count=0;
	w = win,h=hin;
	
	myfor(i,w)myfor(j,h)cin >> c[i][j];
	myfor(i,w)myfor(j,h){
		if(!done[i][j])count+= dfs(i,j);
	}
	return count;
}

int main(){
	int win=1,hin=1,i;
	vector<int> ans;
	while(win != 0 && hin != 0){
		cin >> win >> hin;
		int cnt=0;
		if(win != 0 && hin != 0){
			done.assign(50,vector<bool>(50,false));
			ans.push_back(mainloop(hin,win));
		}
	}
	myfor(i,ans.size())cout << ans[i] << endl;
	return 0;
}