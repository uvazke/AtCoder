#include <cmath>
#include <iostream>
#include <queue>
#include <vector>
#define myFor(N) for (int i = 0; i < N; i++)
#define myForFL(first, last) for (int i = first; i < last; i++)
using namespace std;

typedef struct {
  int nodeNum;
  vector<int> edgesTo;
  int color;
} Node;

vector<Node> nodes(N);

int main(void) {
  int N, M, ans = 1;
  ;
  int A[20], B[20];
  bool isChecked[20];
  queue<Node> nextNodes;
  cin >> N >> M;

  myFor(N) { nodes[i].nodeNum = i; }
  myFor(M) {
    cin >> A[i] >> B[i];
    nodes[A[i]].edgesTo.push_back(B[i]);
    nodes[B[i]].edgesTo.push_back(A[i]);
  }
  myFor(N) { isChecked[i] = false; }

  myFor(N) {
    if (!isChecked[i]) {
      ans *= 3;
      isChecked[i] = true;
      for (int j = 0; j < nodes[i].edgesTo.size(); j++) {
        if (!isChecked[nodes[i].edgesTo[j]]) {
          nextNodes.push(nodes[nodes[i].edgesTo[j]]);
        }
      }
      while (!nextNodes.empty()) {
        Node frontNode = nextNodes.front();
        nextNodes.pop();
        if (isChecked[frontNode.nodeNum]) {
          continue;
        }
        isChecked[frontNode.nodeNum] = true;
        for (int j = 0; j < nodes[i].edgesTo.size(); j++) {
          if (!isChecked[nodes[i].edgesTo[j]]) {
            nextNodes.push(nodes[nodes[i].edgesTo[j]]);
          }
        }
      }
    }
  }
  return 0;
}

void NodeCheck(Node node) {
  bool r = false, g = false, b = false;

  for (int i : node.edgesTo) {
    if (nodes[i].color == 1) {
      r = true;
    }
  }
}