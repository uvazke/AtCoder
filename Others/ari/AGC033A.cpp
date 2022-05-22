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
	int H,W,N,i,j,y,x,sh=0,sw=0;
	vector<pair<int,int> >black_p;
	cin >> H >> W;
	vector<vector<int> >dist(H,vector<int>(W,INF));
	vector<string> s(H);

	myfor(i,H){
		cin >> s[i];
	}
	myfor(i,H)myfor(j,W)if(s[i][j] == '#')black_p.push_back(pair<int,int>(i,j));
	
	queue<pair<int, int> >q;
	myfor(i,black_p.size()){
		sh = black_p[i].first, sw=black_p[i].second;
		q.push(pair<int,int>(sh,sw));
		dist[sh][sw] = 0;
	}
	vector<vector<bool> >done(H,vector<bool>(W,false));
	while(!q.empty()){
		y = q.front().first;
		x = q.front().second;
		q.pop();
		if(done[y][x])continue;
		done[y][x] = true;
		myfor(j,4){
			ifMeetBoundaryCondition(x+dx[j],W,0,y+dy[j],H,0){
				if(s[y+dy[j]][x+dx[j]] != '#' && !done[y+dy[j]][x+dx[j]]){
					q.push(pair<int,int>(y+dy[j],x+dx[j]));
					dist[y+dy[j]][x+dx[j]] = min(dist[y][x] + 1,dist[y+dy[j]][x+dx[j]]);
				}
			}
		}
	}
	
	int ans=0;
	myfor(i,H){
		 ans = max(ans,*max_element(dist[i].begin(), dist[i].end()));
	}
	cout << ans << endl;


	return 0;
}