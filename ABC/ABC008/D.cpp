#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
using namespace std;
#define f(i, n) for(int i=0; i < n; i++)

int N,X[30],Y[30];
struct Co{
	int coord;
	int ind;
};

bool coordDesc(const Co& a, const Co& b){
	return a.coord > b.coord;
}

// int getGold(int x0, int y0, int x1 , int y1){
// 	int nextX, nextY;
// 	int ans = 0;
// 	f(i,N){
// 		int gold = 0;
// 		nextX = X[i]-1;
// 		nextY = Y[i]-1;
// 		if(nextX <= x1 && nextX >= x0 && nextY <= y1 && nextY >= y0) {
// 			gold += getGold(nextX+1, nextY+1, x1, y1);
// 			gold += getGold(x0, nextY+1, nextX-1,y1);
// 			gold += getGold(nextX+1, y0, x1,nextY-1);
// 			gold += getGold(x0, y0, nextX-1,nextY-1);
// 			gold += x1 - x0 + y1 - y0 + 1;
// 		}
// 		ans = max(ans,gold);
// 	}
// 	return ans;
// }

int dp[32][32][32][32];
bool dpDone[32][32][32][32];
vector<Co> x,y;
int solve(Co x0, Co y0, Co x1, Co y1){
	if(dpDone[x0.ind][y0.ind][x1.ind][y1.ind])return dp[x0.ind][y0.ind][x1.ind][y1.ind];
	dpDone[x0.ind][y0.ind][x1.ind][y1.ind] = true;
	f(m,N){
		if(x[m].coord <= x1.coord && x[m].coord >= x0.coord && y[m].coord <= y1.coord && y[m].coord >= y0.coord){
			int gold = 0;
			Co tmpx0 = {x[m].coord + 1 , x[m].ind};
			Co tmpy0 = {y[m].coord + 1 , y[m].ind};
			Co tmpx1 = {x[m].coord - 1 , x[m].ind};
			Co tmpy1 = {y[m].coord - 1 , y[m].ind};
			gold += solve(tmpx0, tmpy0,    x1,    y1);
			gold += solve(   x0, tmpy0, tmpx1,    y1);
			gold += solve(tmpx0,    y0,    x1, tmpy1);
			gold += solve(   x0,    y0, tmpx1, tmpy1);
			dp[x0.ind][y0.ind][x1.ind][y1.ind] = max(dp[x0.ind][y0.ind][x1.ind][y1.ind], gold + x1.coord - x0.coord + y1.coord - y0.coord + 1);
		}
	}
	return dp[x0.ind][y0.ind][x1.ind][y1.ind];
}
int main() {
	int W,H;
	cin >> W >> H >> N;
	
	f(i,N){
		cin >> X[i] >> Y[i];
		Co xtmp = {X[i]-1, i+1};
		Co ytmp = {Y[i]-1, i+1};
		x.push_back(xtmp);
		y.push_back(ytmp);
	}

	f(i,N)f(j,N)f(k,N)f(l,N){
		dp[i][j][k][l] = 0;
		dpDone[i][j][k][l] = false;
	}
	Co a = {0,0},b = {0,0},c={W-1,N+1},d={H-1,N+1};
	int gold = solve(a,b,c,d);

	cout << gold << endl;
	
	return 0;
}