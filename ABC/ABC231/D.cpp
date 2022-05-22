#include <algorithm>
#include <float.h>
#include <iostream>
#include <list>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <vector>
#define myfor(i, N) for (i = 0; i < N; i++)
#define myforFL(i, f, l) for (i = f; i < l; i++)
#define myforInv(i, N) for (i = N; i >= 0; i--)
#define myforFLInv(i, f, l) for (i = f; i > l; i--)
using namespace std;

struct Node{
    int number;
    vector<Node*> neighbors;
};
bool check[100001];
bool CheckNode(Node node);
bool Check(vector<Node> nodes) {
    for(auto next: nodes){
        if(check[next.number]){
            return false;
        }
        check[next.number] = true;
        return CheckNode(next);
    }
    return true;
}

bool CheckNode(Node node){
    if(check[node.number]){
        return false;
    }
    check[node.number] = true;
    for(auto neighbor: node.neighbors){
        if(CheckNode(*neighbor) == false){
            return false;
        }
    }
    return true;
}
int main() {
    int N,M,list[100001],i;
    vector<Node> nodes;
    vector<int> A;
    cin >> N >> M;
    myfor(i, N) { 
        list[i] = 0;
        check[i] = false;
    }
    if(M == 0){
        cout << "Yes" << endl;
    }
    myfor(i,M){
        int a, b;
        cin >> a >> b;
        Node node,node2;
        node.number = a;
        node2.number = b;
        Node *node2Pt = &node2, *nodePt = &node;

        if(node.neighbors.size() >= 2 || node2.neighbors.size() >= 2){
            cout << "No" << endl;
            return 0;
        }

        node.neighbors.push_back(node2Pt);
        nodes.push_back(node);
        node2.neighbors.push_back(nodePt);
    }

    if(Check(nodes)){
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
    return 0;
    return 0;
}
