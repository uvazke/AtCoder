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
//戦略： 枝の重みを0と1（道と壁）にして，やる.place[i][j] = min(omomi)を入れて，place[gx][gy] <= 2 ならok

int main(){
	int H,W,N,i,j,y,x,sh,sw,gh,gw;
	vector<pair<int,int> >black_p;
	cin >> H >> W;
	vector<string> s(H);

	myfor(i,H){
		cin >> s[i];
	}
	myfor(i,H)myfor(j,W){
		if(s[i][j] == 's')sh = i, sw = j;
		if(s[i][j] == 'g')gh = i, gw = j;
	}
	deque<pair<int, int> >q;
	q.push_front(pair<int, int>(sh,sw));


	vector<vector<int> >place(H,vector<int>(W,INF));
	place[sh][sw] = 0;
	long refnum = 0; 
	while(!q.empty()){
		y = q.front().first;
		x = q.front().second;
		q.pop_front();
		myfor(j,4){
			refnum++;
			ifMeetBoundaryCondition(x+dx[j],W,0,y+dy[j],H,0)if(place[y+dy[j]][x+dx[j]]==INF){
				if((s[y+dy[j]][x+dx[j]] == '.'||s[y+dy[j]][x+dx[j]] == 'g')){
					q.push_front(pair<int,int>(y+dy[j],x+dx[j]));
					place[y+dy[j]][x+dx[j]] = place[y][x];	
				}
				if(s[y+dy[j]][x+dx[j]] == '#'&& place[y+dy[j]][x+dx[j]]!=0){
					q.push_back(pair<int,int>(y+dy[j],x+dx[j]));
					place[y+dy[j]][x+dx[j]] = place[y][x]+1;
				}
			}
		}
	}
	string ans = "NO";
	if(place[gh][gw] <= 2)ans = "YES";
	cout << ans << endl;
	return 0;
}