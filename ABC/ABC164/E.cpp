#include <iostream>
#include <vector>
#include <numeric>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <unordered_map>
#include <queue>
#define myfor(i,N) for(i=0;i<N;i++)
#define myforFL(i,f,l) for(i=f;i<l;i++)
#define MAXSILVER 50*49
#define INF pow(10,16)

using namespace std;

struct Node{
	long number;
	long time;
	long silver;
	bool operator > (const Node &node1) const {
    return node1.time > time;
	};
	bool operator < (const Node &node1) const {
    return node1.time < time;
	};
};

int main(void){
	long i,j;
	long N,M,S,A[100],B[100],C[51],D[51],U[100],V[100],change_number;
	long dp[51][MAXSILVER+1] ={};
	priority_queue<Node> q;
	
	cin >> N >> M >> S;
	
	myfor(i,M)cin >> U[i] >> V[i] >> A[i] >> B[i];
	myforFL(i,1,N+1)cin >> C[i] >> D[i];
	myfor(i,N+1)myfor(j,MAXSILVER+1){
		dp[i][j]=INF;
	}
	S = min(S,(long)MAXSILVER);
	Node node = {1,0,S};
	dp[1][S]=0;
	q.push(node);
	while(!q.empty()){
		node = q.top();
		q.pop();
		if(dp[node.number][node.silver] < node.time)continue;
		//現地にとどまって一回だけ両替した場合をqueueに入れる
		if(node.silver +C[node.number] <= MAXSILVER && dp[node.number][node.silver+ C[node.number]] > node.time+D[node.number]){
			dp[node.number][node.silver+ C[node.number]] = node.time+D[node.number];
			q.push((Node){node.number,node.time+D[node.number],node.silver+ C[node.number]});
		}
		//隣接した都市に移動するケース
		myfor(i,M){
			if(U[i] == node.number){	
				if(node.silver >= A[i] && node.time+B[i] < dp[V[i]][node.silver-A[i]]){
					dp[V[i]][node.silver-A[i]]=node.time+B[i];
					q.push((Node){V[i],node.time+B[i],node.silver-A[i]});
				}
			}else if(V[i] == node.number){
				if(node.silver >= A[i] && node.time+B[i] < dp[U[i]][node.silver-A[i]]){
					dp[U[i]][node.silver-A[i]]=node.time+B[i];
					q.push((Node){U[i],node.time+B[i],node.silver-A[i]});
				}
			}
		}
	}
	myforFL(i,2,N+1){
		long ans = INF;
		myfor(j,MAXSILVER){
			ans = min(dp[i][j],ans);
		}
		cout << ans << endl;
	}
	return 0;
}