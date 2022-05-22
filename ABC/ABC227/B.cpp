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
bool IsValid(int S) {
  int j, k;
  myforFL(j,1, 251) {
    myforFL(k,1, 251) {
      int s = 4 * j*k + 3*(j+k);
      if(s > S){
          k = 251;
          continue;
      }
      if (S == s) {
          return true;
      }
    }
  }
  return false;
}

int main() {
  int N;
  cin >> N;
  int i, ans = 0;
  myfor(i, N) {
    int S;
    cin >> S;
    ans = IsValid(S) ? ans : ans + 1;
  }
  cout << ans<< endl;
  return 0;
}