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

int main() {
  int M;
  int u[36], v[36], p[8];
  cin >> M;
  int i;
  myfor(i, M) { cin >> u[i] >> v[i]; }
  string placement = "000000000";
  myfor(i, 8) {
    cin >> p[i];
    placement[p[i] - 1] = i + '1';
  }

  queue<string> queue;
  map<string, int> map;
  map[placement] = 0;
  queue.push(placement);
  while (!queue.empty()) {
    string front = queue.front();
    queue.pop();
    int count = map[front];
    if (front == "123456780") {
      cout << count << endl;
      return 0;
    }
    myfor(i, M) {
      string tmp = front;
      if (tmp[u[i] - 1] == '0' || tmp[v[i] - 1] == '0') {
        swap(tmp[u[i] - 1], tmp[v[i] - 1]);
        if (map.count(tmp) == 0) {
          int newCount = count + 1;
          map[tmp] = newCount;
          queue.push(tmp);
          continue;
        }
      }
    }
  }
  cout << -1 << endl;
  return 0;
}