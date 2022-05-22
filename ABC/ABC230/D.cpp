
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

int main() {
    int N, D;
    cin >> N >> D;
    int i;
    map<int, int> spans;
    myfor(i, N) {
        int l, r;
        cin >> l >> r;

        auto lItr = spans.lower_bound(l);
        if(lItr != spans.end() && lItr->first == l ) {
            if(spans[lItr->first] >= r){
                spans.erase(lItr);
                spans[l] = r;
            }
            continue;
        }
        spans[l] = r;
    }
    auto minIt = min_element(
        spans.begin(), spans.end(),
        [](const auto &l, const auto &r) { return l.second < r.second; });
    auto ans = 0;
    while(minIt != spans.end()) {
        auto rightBound = minIt->second + D-1;
        auto nextItr = spans.upper_bound(rightBound);
        spans.erase(spans.begin(), nextItr);
        minIt = min_element(
        spans.begin(), spans.end(),
        [](const auto &l, const auto &r) { return l.second < r.second; });
        ans++;
    }
    cout << ans << endl;
    return 0;
}