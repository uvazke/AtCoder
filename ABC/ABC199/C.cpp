#include <cmath>
#include <iostream>

#define myFor(N) for (int i = 0; i < N; i++)
#define myForFL(first, last) for (int i = first; i < last; i++)
using namespace std;

int main(void) {
  int N;
  string S, ans = "";
  int Q;
  int T[300000], A[300000], B[300000], dp[400000];

  cin >> N;
  cin >> S;
  cin >> Q;
  for (int i = 0; i < Q; i++) {
    cin >> T[i] >> A[i] >> B[i];
  }
  for (int i = 0; i < 2 * N; i++) {
    dp[i] = i;
  }
  int buffer = 0;
  for (int i = 0; i < Q; i++) {
    if (T[i] == 2) {
      buffer = N - buffer;
    } else {
      int a = A[i] + buffer - 1 < 2 * N ? A[i] + buffer - 1 : A[i] - buffer - 1;
      int b = B[i] + buffer - 1 < 2 * N ? B[i] + buffer - 1 : B[i] - buffer - 1;
      int tmp = dp[a];
      dp[a] = dp[b];
      dp[b] = tmp;
    }
  }
  myFor(2 * N) { ans += S[dp[i]]; }
  if (buffer != 0) {
    ans = ans.substr(N, 2 * N) + ans.substr(0, N);
  }
  cout << ans << endl;
  return 0;
}