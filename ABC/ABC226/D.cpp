#include <algorithm>
#include <deque>
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

int CalculateGCD(int x, int y) {
    auto target = abs(x) > abs(y) ? abs(x) : abs(y);
    auto residue = abs(x) > abs(y) ? abs(y) : abs(x);
    while(residue > 0) {
        auto nextResidue = target % residue;
        target = residue;
        residue = nextResidue;
  }
  return target;
}

int main() {
    int N, x[500], y[500], i, j;
    map<pair<int, int>, int> magic;
    cin >> N;
    myfor(i, N) { cin >> x[i] >> y[i]; }
    myfor(i, N) {
        myfor(j, N) {
            if(i == j)
                continue;
            auto dx = x[i] - x[j];
            auto dy = y[i] - y[j];
            auto gcd = CalculateGCD(dx, dy);
            magic[{dx / gcd, dy / gcd}] = 1;
        }
    }
    cout << magic.size() << endl;
    return 0;
}