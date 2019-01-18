#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
string s[400];
int H,W;
long color[2];
bool list[400][400];

void dfs(int x, int y){
	char now = s[x][y];

	list[x][y] = false;

	for(int i=0;i<4;i++){
		if(x + dx[i] >= 0 && x + dx[i] < H && y + dy[i] >= 0  && y + dy[i] < W && list[x+dx[i]][y+dy[i]] && s[x+dx[i]][y+dy[i]] != now){
			if(s[x+dx[i]][y+dy[i]] == '#') color[0] += 1;
			else color[1] += 1;
			dfs(x+dx[i],y+dy[i]);
		}
	}
}

int main(void){
	cin >> H >> W;
	for(int i=0; i<H; i++){
		cin >> s[i];
	}
	for(int i=0; i<H; i++){
		for(int j=0; j<W; j++){
			list[i][j] = true;
		}
	}
	long ans =0;

	for(int i=0; i<H; i++){
		for(int j=0; j<W; j++){
			if(s[i][j] == '#' && list[i][j]){
				color[0] = 1;
				color[1] = 0;
				dfs(i,j);
				ans += color[0] * color[1];
			}
		}
	}

	cout << ans << endl;
	return 0;
}

