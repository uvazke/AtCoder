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
#define INF pow(10,9)
using namespace std;


typedef struct Node{
	vector<int> edges_to;
}Node_t;

vector<Node_t> node(100000);
vector<bool>done(100000,false);
vector<int>michishirube(100000,INF);


int main(){
	int i,j,ind,pre_ind;
	int N,M;
	cin >> N >> M;
	vector <int> A(M),B(M);
	myfor(i,M){
		cin >> A[i] >> B[i];
		node[A[i]-1].edges_to.push_back(B[i]-1);
		node[B[i]-1].edges_to.push_back(A[i]-1);
	}
	queue<pair<int,int> >q;
	q.push(pair<int,int>(0,0));
	while(!q.empty()){
		ind = q.front().first;
		pre_ind = q.front().second;
		q.pop();
		if(done[ind])continue;
		done[ind] = true;
		michishirube[ind] = pre_ind;
		myfor(i,node[ind].edges_to.size())q.push(pair<int,int>(node[ind].edges_to[i],ind));
	}
	myfor(i,N)if(done[i] == false){
		cout << "No" << endl;
		return 0;
	}
	cout << "Yes" << endl;
	myforFL(i,1,N){
		cout << michishirube[i]+1 << endl;
	}


	return 0;
}