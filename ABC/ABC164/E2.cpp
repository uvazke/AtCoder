#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>

#define myfor(i,N) for(i=0;i<N;i++)
#define myforFL(i,f,l) for(i=f;i<l;i++)
#define MAXSILVER 49*50
#define INF pow(10,16)

using namespace std;
typedef struct Node{
	vector<long> edges_to;//移動可能先
	vector<long> edge_costs;//移動に必要な銀貨
	vector<long> edge_times;//移動にかかる時間
	long exchange_rate;
	long exchange_time;
	
	
}Node_t;

typedef struct Status{
	long city_number;
	long silver;//所持している銀貨
	long time;//スタート時点からの経過時間

	bool operator > (const Status &st1) const {
		return st1.time > time;
	}
	bool operator < (const Status &st1) const {
		return st1.time < time;
	}
}Status_t;

int main(){
	int i,j;
	long N,M,S;
	priority_queue<Status_t> q; 
	vector<vector<long> > dp(51,vector<long>(MAXSILVER+1, INF));//経過時間(都市，残銀貨)

	cin >> N >> M >> S;
	S = min(S,(long)MAXSILVER);
	vector<Node_t> nodes(N+1);

	myfor(i,M){
		long u,v,a,b;
		cin >> u >> v >> a >> b;
		nodes[u].edges_to.push_back(v);
		nodes[u].edge_costs.push_back(a);
		nodes[u].edge_times.push_back(b);
		nodes[v].edges_to.push_back(u);
		nodes[v].edge_costs.push_back(a);
		nodes[v].edge_times.push_back(b);
	}
	myforFL(i,1,N+1){
		long c,d;
		cin >> c >> d;
		nodes[i].exchange_rate = c;
		nodes[i].exchange_time = d;
	}

	dp[1][S] = 0;
	Status_t status1 = {1,S,0};
	q.push(status1);
	while(!q.empty()){
		status1 = q.top();
		q.pop();
		long c,s,t;
		c = status1.city_number;
		s = status1.silver;
		t = status1.time;
		
		if(dp[c][s] < t)continue;
		
		long charged_s = s + nodes[c].exchange_rate;
		
		if(charged_s <= MAXSILVER){
			if(dp[c][charged_s] > t + nodes[c].exchange_time){
				dp[c][charged_s] = t + nodes[c].exchange_time;
				q.push((Status_t){c,charged_s,t + nodes[c].exchange_time});
			}
		}
		
		long n = nodes[c].edges_to.size();
		
		myfor(i,n){
			long move_to = nodes[c].edges_to[i];
			long move_cost = nodes[c].edge_costs[i];
			long move_time = nodes[c].edge_times[i];
			if(s >= move_cost){
				if(dp[move_to][s - move_cost] > t + move_time){
					dp[move_to][s - move_cost] = t + move_time;
					q.push((Status_t){move_to,s - move_cost,t + move_time});
				}
			}
		}
	}

	myforFL(i,2,N+1){
		long ans = INF;
		myfor(j,MAXSILVER+1){
			ans = min(ans,dp[i][j]);
		}
		cout << ans << endl;
	}
	return 0;

}