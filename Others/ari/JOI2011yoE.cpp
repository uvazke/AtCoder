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
#define ifMeetBoundaryContdition(x,xMax,xMin,y,yMax,yMin) if(x < xMax && x >= xMin &&y < yMax && y >= yMin)
#define INF pow(10,9)
using namespace std;

int dx[] = {1,-1,0,0},dy[]={0,0,1,-1};

int main(){
	int H,W,N,i,j,y,x,sh,sw,cheeze=1,cheeze_max = 1, total_time=0;
	cin >> H >> W >> N;
	vector<string> s(H);
	myfor(i,H){
		cin >> s[i];
	}
	myfor(i,H)myfor(j,W){
		if(s[i][j]=='S'){
			sh = i;
			sw = j;
		}
		if(s[i][j] != 'S' && s[i][j] != '.' && s[i][j] != 'X'){
			cheeze_max = max(s[i][j]- '0', cheeze_max); 
		}
	}

	queue<pair<int, int> >q;
	q.push(pair<int,int>(sh,sw));
	vector<vector<int> >time(H,vector<int>(W,INF));
	time[sh][sw] = 0;
	while(!q.empty() && cheeze <= cheeze_max){
		y = q.front().first;
		x = q.front().second;
		q.pop();
		myfor(i,4){
			ifMeetBoundaryContdition(x+dx[i],W,0,y+dy[i],H,0){
				if(s[y+dy[i]][x+dx[i]] == char(cheeze+'0')){
					total_time += time[y][x] +1;
					cheeze++;
					queue<pair<int, int> >nq;
					swap(q,nq);
					q.push(pair<int,int>(y+dy[i],x+dx[i]));
					vector<vector<int> >ntime(H,vector<int>(W,INF));
					swap(time,ntime);
					time[y+dy[i]][x+dx[i]] = 0;
					break;
				}
				if(s[y+dy[i]][x+dx[i]] != 'X' && time[y+dy[i]][x+dx[i]] == INF){
					time[y+dy[i]][x+dx[i]] = time[y][x] +1;
					q.push(pair<int,int>(y+dy[i],x+dx[i]));
				}
			}
		}
	}
	cout << total_time << endl;


	return 0;
}