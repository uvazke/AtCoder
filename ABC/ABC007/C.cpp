#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

#define INF 1000000000

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
string c[50];
struct Data{
	int x;
	int y;
	int cost;
};
bool operator < (const Data &data1, const Data &data2){
	return data1.cost < data2.cost;
}
bool operator > (const Data &data1, const Data &data2){
	return data1.cost > data2.cost;
}


bool done[50][50];
int cost[50][50];
int solve(int sx,int sy,int gx, int gy,int R,int C){
	int cx,cy;
	cx = sx - 1;
	cy = sy - 1;
	priority_queue<Data,vector<Data>, greater<Data> > q;
	Data tmp = {cx,cy,0};
	q.push(tmp);
	for (int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			done[i][j] = false;
			cost[i][j] = INF;
		}
	}
	cost[cx][cy] = 0;
	while(!q.empty()){
		cx = q.top().x;
		cy = q.top().y;
		q.pop();
		if(done[gx-1][gy-1])break;
		if(done[cx][cy])continue;
		done[cx][cy] = true;
		for(int i=0;i<4;i++){
			if(cx + dx[i] < R && cx + dx[i] > 0 && cy + dy[i] < C && cy + dy[i] > 0){
				if(!done[cx+dx[i]][cy+dy[i]] && c[cx+dx[i]][cy+dy[i]] == '.' ){
					cost[cx+dx[i]][cy+dy[i]] = min(cost[cx+dx[i]][cy+dy[i]],cost[cx][cy]+1);
					Data tmp2 = {cx+dx[i], cy+dy[i],cost[cx+dx[i]][cy+dy[i]]};
					q.push(tmp2);
				}
			} 
		}
	}
	return 0;
}
int main(){
	int R, C;
	int sy, sx, gx,gy;
	

	cin >> R >> C;
	cin >> sx >>sy >> gx >> gy;

	for (int i=0; i< R; i++){
		cin >> c[i];
	}
	solve(sx,sy,gx,gy,R,C);

	cout << cost[gx-1][gy-1] << endl;
	return 0;
}