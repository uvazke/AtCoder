#include <algorithm>
#include <iostream>
#include <list>
#include <set>
#include <vector>
#include<cmath>
using namespace std;

long GetVal(long num, long k) {
  long count = 0;
  long ans = 0;
  long stepedNum = num;
  while (stepedNum > 0) {
    long first = stepedNum % 10;
    long times = pow(k, count);
    ans += first * times;
    stepedNum /= 10;
    count++;
  }
  return ans;
}

int main() {
  long K, A, B;
  cin >> K;
  cin >> A >> B;
  long newA = GetVal(A, K);
  long newB = GetVal(B, K);
  long ans = (long)newA * (long)newB;
  cout << ans << endl;
  return 0;
}
