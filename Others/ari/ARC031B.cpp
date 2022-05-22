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

bool oneIsland(vector<string> A,int x, int y,int cnt){
	int i,j,nx,ny,nextx, nexty, land = 0;
	int dx[] = {1,-1,0,0}, dy[] = {0,0,1,-1};
	vector<vector<bool> >done(10,vector<bool>(10,false));
	queue <pair<int, int> >q;
	q.push(pair<int, int>(x,y));
	while(!q.empty()){
		nx = q.front().first;
		ny = q.front().second;
		q.pop();
		if(done[nx][ny] == true)continue;
		land ++;
		myfor(i,4){
			nextx = nx + dx[i];
			nexty = ny + dy[i];
			if(nextx >= 0 && nextx < 10 && nexty >= 0 && nexty < 10){
				if(A[nextx][nexty] == 'o')q.push(pair<int, int>(nextx,nexty));
			}
		}
		done[nx][ny] = true;
	}
	if(cnt == land) return true;
	return false;
}

int main(){
	int i,j,cnt=0;
	vector<string> A(10);

	myfor(i,10){
		cin >> A[i];
	}
	//陸地のマス数
	myfor(i,10)myfor(j,10){
		if(A[i][j] == 'o')cnt++;
	}

	myfor(i,10)myfor(j,10){
		vector <string> B = A;
		if(B[i][j] == 'x'){
			B[i][j] = 'o';
			if(oneIsland(B,i,j,cnt+1)==true){
				cout << "YES" << endl;
				return 0; 
			}
		}
	}

	cout << "NO" << endl;
	return 0;
}
