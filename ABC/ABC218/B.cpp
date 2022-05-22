#include <algorithm>
#include <iostream>
#include <list>
#include <set>
#include <vector>
using namespace std;

int main() {
  for(int i=0;i<26;i++){
      int s;
      cin >> s;
      cout << char((int('a') + s-1));
  }
  cout << endl;
  return 0;
}
