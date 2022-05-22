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

using namespace std;
typedef struct Node{
	int nodeNum;
	vector<int> edgesTo;
}Node_t;
vector<bool> done(100+1,false);
vector<Node_t> Nodes(100+1);
vector<vector<bool> > usedEdge(100+1,vector<bool>(100+1,false));
int dfs(int nodeNum){
	if(done[nodeNum]) return 0;
	done[nodeNum] = true;
	Node node = Nodes[nodeNum];
	int i;
	myfor(i,node.edgesTo.size()){
		if(usedEdge[nodeNum][node.edgesTo[i]] == false){
			usedEdge[nodeNum][node.edgesTo[i]] = true;
			usedEdge[node.edgesTo[i]][nodeNum] = true;
			if(dfs(Nodes[node.edgesTo[i]].nodeNum)==0){
				return 0;
			}
		}
		
	}
	return 1;
}
int main(){
	int N,M,i,j,count=0;
	cin >> N >> M;
	vector<int> u(M),v(M);
	
	
	
	myfor(i,N)Nodes[i+1].nodeNum = i+1;
	myfor(i,M){
		cin >> u[i] >> v[i];
		Nodes[u[i]].edgesTo.push_back(v[i]);
		Nodes[v[i]].edgesTo.push_back(u[i]);
	}
	myforFL(i,1,N+1){
		count += dfs(i);
	}
	cout << count << endl; 
	return 0;
}