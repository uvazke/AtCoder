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
    vector<pair<int, int>> choco, box;
    int N, M, a[200000],b[200000],c[200000],d[200000];
    cin >> N >> M;
    int i;
    myfor(i, N) {
        cin >> a[i];
    }
    myfor(i, N) {
        cin >> b[i];
    }
    myfor(i, M) {
        cin >> c[i];
    }
    myfor(i, M) {
        cin >> d[i];
    }
    myfor(i, N) { choco.push_back(pair<int,int>(a[i], b[i])); }
    myfor(i, M) { box.push_back(pair<int,int>(c[i], d[i])); }

    sort(box.begin(), box.end());
    sort(choco.begin(), choco.end(), greater<pair<int, int>>());
    
    return 0;
}