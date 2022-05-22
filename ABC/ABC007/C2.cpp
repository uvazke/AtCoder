#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#define myfor(i,N) for(i=0;i<N;i++)
#define myforFL(i,f,l) for(i=f;i<l;i++)

using namespace std;

int main(void){
	int R, C,y,x, sy, sx, gy, gx,i,j,d[50][50],dx[] = {1,-1,0,0}, dy[] = {0,0,1,-1};
	bool done[50][50];
	char c[50][50];
	queue <pair<int, int> > que;
	pair<int, int> p;
	cin >> R >> C;
	cin >> sy >> sx;
	cin >> gy >> gx;
	myfor(i,R)myfor(j,C){
		cin >> c[i][j];
		done[i][j] = false;
	}
	p = make_pair(sy-1,sx-1);
	que.push(p);
	d[sy-1][sx-1]=0;
	done[sy-1][sx-1] = true;
	while(que.size() != 0){
		y = que.front().first;
		x = que.front().second;
		que.pop();
		myfor(i,4)if(y+dy[i] < R && y+dy[i] > -1 && x+dx[i] < C && x+dx[i] > -1){
			if(c[y+dy[i]][x+dx[i]] == '.' && done[y+dy[i]][x+dx[i]] == false){
				p = make_pair(y+dy[i],x+dx[i]);
				que.push(p);
				d[y+dy[i]][x+dx[i]] = d[y][x] + 1;
				done[y+dy[i]][x+dx[i]] = true;
			}
		}
	}
	cout << d[gy-1][gx-1] << endl;
	return 0;
}