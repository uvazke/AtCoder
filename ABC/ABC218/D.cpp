#include <algorithm>
#include <iostream>
#include <list>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

int main() {
  int N;
  long x[2000], y[2000], ans = 0;
  queue<pair<long, long>> sameX;
  vector<pair<long, long>> sameY;
  bool done[2000];
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> x[i] >> y[i];
    done[i] = false;
  }
  for (int i = 0; i < N; i++) {
    done[i] = true;
    sameY.clear();
    for (int j = i + 1; j < N; j++) {
      if (x[i] == x[j] && !done[j]) {
        sameX.push(pair<long, long>(x[j], y[j]));
      }
      if (y[i] == y[j] && !done[j]) {
        sameY.push_back(pair<long, long>(x[j], y[j]));
      }
    }

    while (!sameX.empty()) {
      pair<long, long> xy = sameX.front();
      sameX.pop();
      long y1 = xy.second;
      for (int j = 0; j < sameY.size(); j++) {
        long x1 = sameY[j].first;
        for (int k = i; k < N; k++) {
          if (x[k] == x1 && y[k] == y1) {
            ans++;
          }
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
