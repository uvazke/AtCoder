#include <iostream>

using namespace std;

int main() {
  long N, A[200];
  cin >> N;

  for (int i = 0; i < 200; i++) {
    A[i] = 0;
  }

  for (int i = 0; i < N; i++) {
    long K;
    cin >> K;
    A[K % 200]++;
  }

  long ans = 0;
  for (int i = 0; i < 200; i++) {
    if (A[i] > 0) {
      ans += A[i] * (A[i] - 1) / 2;
    }
  }

  cout << ans << endl;
}