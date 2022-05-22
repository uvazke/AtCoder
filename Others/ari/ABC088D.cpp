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
#define ifMeetBoundaryCondition(x,xMax,xMin,y,yMax,yMin) if(x < xMax && x >= xMin &&y < yMax && y >= yMin)
#define INF pow(10,9)
using namespace std;

int dx[] = {1,-1,0,0},dy[]={0,0,1,-1};

int main(){
	int H,W,N,i,j,y,x,sh=0,sw=0,black_cell_count =0,ans;
	cin >> H >> W;
	vector<string> s(H);
	myfor(i,H){
		cin >> s[i];
	}
	myfor(i,H)myfor(j,W){
		if(s[i][j] == '#')black_cell_count++;
	}

	queue<pair<int, int> >q;
	q.push(pair<int,int>(sh,sw));
	vector<vector<bool> >done(H,vector<bool>(W,false));
	vector<vector<int> >count(H,vector<int>(W,INF));
	count[sh][sw] = 1;
	while(!q.empty()){
		y = q.front().first;
		x = q.front().second;
		q.pop();
		if(done[y][x])continue;
		done[y][x] = true;
		
		myfor(i,4){
			ifMeetBoundaryCondition(x+dx[i],W,0,y+dy[i],H,0){
				if(s[y+dy[i]][x+dx[i]] != '#' && !done[y+dy[i]][x+dx[i]]){
					q.push(pair<int,int>(y+dy[i],x+dx[i]));
					count[y+dy[i]][x+dx[i]] = count[y][x] + 1;
				}
			}
		}
	}
	ans = H*W - count[H-1][W-1] - black_cell_count;
	if(ans < 0)ans = -1; 
	cout << ans  << endl;


	return 0;
}