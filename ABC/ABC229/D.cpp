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
    int K;
    string S;
    cin >> S;
    cin >> K;
    vector<size_t> positions;
    auto pos = S.find(".", 0);
    while(pos != string::npos){
        positions.push_back(pos);
        pos = S.find(".",pos+1);
    }
    auto size =positions.size();
    int i;
    auto ans = size > K ? positions[K] : S.size();
    myforFL(i, K + 1, size) {
        ans = max(ans, positions[i] - positions[i - K - 1]-1);
    }
    ans = size > K ? max(ans, S.size() - positions[size -K -1] - 1) : ans;
    cout << ans << endl;
    return 0;
}