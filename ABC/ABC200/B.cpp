#include <iostream>

using namespace std;

int main() {
  long N, K;
  cin >> N >> K;
  for (long i = 0; i < K; i++) {
    N = N % 200 == 0 ? N / 200 : N * 1000 + 200;
  }
  cout << N << endl;
}