#include <algorithm>
#include <iostream>
#include <list>
#include <set>
#include <vector>
using namespace std;

int main() {
  int A,B,C;
  cin >> A >> B >> C;
  int residue = B % C;
  int ans = B - residue;
  if(B - residue >= A) {
      cout << ans << endl;
      return 0;
  }
  cout << -1 << endl;
  return 0;
}
