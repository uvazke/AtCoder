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

int main(){
	int i,j,H,W,sx,sy,x,y,nx,ny;
	int dx[] ={1,-1,0,0},dy[]={0,0,1,-1};
	bool done[500][500];
	vector<string> c(500);
	string ans = "No";
	queue <pair <int, int> > q;
	cin >> H >> W;
	myfor(i,H) cin >> c[i];
	myfor(i,H)myfor(j,W){
		if(c[i][j] == 's'){
			sx=i;
			sy=j;
		}
	}
	myfor(i,H)myfor(j,W)done[i][j] = false;
	q.push(pair <int, int>(sx,sy));
	while(!q.empty()){
		x = q.front().first;
		y = q.front().second;
		q.pop();

		if(done[x][y])continue;
		done[x][y] = true;
		myfor(i,4){

			nx = x + dx[i];
			ny = y + dy[i];
			if(nx >= 0 && nx < H && ny >=0 && ny < W){
				if(c[nx][ny] == '.'){
					q.push(pair <int, int>(nx,ny));
				}
				if(c[nx][ny] == 'g'){
					ans = "Yes";
				}
			}
		}
	}
	cout << ans << endl;

	
	return 0;
}