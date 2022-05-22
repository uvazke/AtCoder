#include <algorithm>
#include <cmath>
#include <iostream>
#include <list>
#include <set>
#include <vector>
using namespace std;

int main() {
  int N;
  int A[100000];
  long dp[10];
  long tmp[10];
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    if (i == 0) {
      dp[A[i]] = 1;
      continue;
    }
    for (int j = 0; j < 10; j++) {
      tmp[(j + A[i]) % 10] += dp[j];
      tmp[(j * A[i]) % 10] += dp[j];
    }
    for(int j = 0; j < 10; j++){
        tmp[j] %= 998244353;
        dp[j] = tmp[j];
        tmp[j] = 0;
    }
  }
  for (int j = 0; j < 10; j++) {
    cout << dp[j] << endl;
  }
  return 0;
}
