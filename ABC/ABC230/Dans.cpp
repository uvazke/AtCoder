
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
    vector<pair<int, int>> spans;
    myfor(i, N) {
        int l, r;
        cin >> l >> r;
        spans.emplace_back(l, r);
    }
    sort(spans.begin(), spans.end(), [](pair<int, int>& a, pair<int, int>& b) { return a.second < b.second; });

    auto ans = 0, x = -D;
    for(auto &[l1, r1] : spans) {
        if(x+D-1<l1){
            ans++;
            x = r1;
        }
    }
    cout << ans << endl;
    return 0;
}