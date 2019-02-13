#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
using namespace std;
#define f(i, n) for(int i=0; i < n; i++)

int N,X[30],Y[30];

int getGold(int x0, int y0, int x1 , int y1){
	int nextX, nextY;
	int ans = 0;
	f(i,N){
		int gold = 0;
		nextX = X[i]-1;
		nextY = Y[i]-1;
		if(nextX <= x1 && nextX >= x0 && nextY <= y1 && nextY >= y0) {
			gold += getGold(nextX+1, nextY+1, x1, y1);
			gold += getGold(x0, nextY+1, nextX-1,y1);
			gold += getGold(nextX+1, y0, x1,nextY-1);
			gold += getGold(x0, y0, nextX-1,nextY-1);
			gold += x1 - x0 + y1 - y0 + 1;
		}
		ans = max(ans,gold);
	}
	
	return ans;
}

int main() {
	int W,H;
	cin >> W >> H >> N;
	f(i,N){
		cin >> X[i] >> Y[i];
	}
	int gold = getGold(0,0,W-1,H-1);

	cout << gold << endl;
	
	return 0;
}