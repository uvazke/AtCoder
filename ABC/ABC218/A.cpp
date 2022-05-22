#include <algorithm>
#include <iostream>
#include <list>
#include <set>
#include <vector>
using namespace std;

int main() {
  int N;
  string S;
  cin >> N;
  cin >> S;
  if(S[N-1] == 'o'){
      cout << "Yes" << endl;
      return 0;
  }
  cout << "No" << endl;
  return 0;
}
